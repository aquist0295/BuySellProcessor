'''
NB: This python script is owned and distributed by E*trade, some modifications have been made by me to tailor this script to my use case.
This script accepts user input for stock symbol(ticker) information from the user.
It will then send a GET request to an E*trade API endpoint to retrieve that ticker information.
The response is then filtered for relevant information i.e price of the security in question.
The filtered information is then passed to the exposed c++ function(GetStockinfo) using the pybind11 binary module(Processor).
'''

import json
# declare the pybind11 binary module which will expose c++ code(GetStockinfo) from: /src/cppFiles/buysellExecution
import Processor as p 
from datetime import datetime


class Market:
 def __init__(self, session, base_url):
    self.session = session
    self.base_url = base_url

 def quotes(self):
    # Get user input for ticker/symbol
    symbols = input("\nPlease enter Stock Symbol: ")

    # URI for the API endpoint
    url = self.base_url + "/v1/market/quote/" + symbols + ".json"

    # Make API call for GET request
    response = self.session.get(url)

    # Get the current time 
    Hour    = int(datetime.now().strftime("%H"))

    # set previous price of stock to arbitrary variable at this time and set ticker information to an empty string
    previous_price  = float(0.0)
    ticker     = "" 

    # Filter response from API GET request from line 28 above
    if response is not None and response.status_code == 200:
    # Only execute this request if hour is between 9am and 4pm EST i.e these are the trading times for the US securities market    
        while Hour >= 9 and Hour <= 16:
            #print("")
            data = response.json()
            if data is not None and "QuoteResponse" in data and "QuoteData" in data["QuoteResponse"]:
                for quote in data["QuoteResponse"]["QuoteData"]:
                    if quote is not None and "Product" in quote and "symbol" in quote["Product"]:
                        ticker = quote["Product"]["symbol"]
                    if quote is not None and "All" in quote and "lastTrade" in quote["All"]:   
                        current_price = quote["All"]["lastTrade"]
                        print("ticker: " + ticker)
                        print("Current Price: " + str(current_price))
                        #Calling exposed C++ function and passing arguments
                        p.GetStockinfo(ticker, current_price)                
            else:
                # Handle errors if response was unable to GET the information from the API endpoint
                if data is not None and 'QuoteResponse' in data and 'Messages' in data["QuoteResponse"] \
                         and 'Message' in data["QuoteResponse"]["Messages"] \
                         and data["QuoteResponse"]["Messages"]["Message"] is not None:
                    for error_message in data["QuoteResponse"]["Messages"]["Message"]:
                        print("Error: " + error_message["description"])
                else:
                    print("Error: Quote API service error")
                    break        
    else:
        print("Error: Quote API service error")




