import json
import Processor
from datetime import datetime


class Market:
 def __init__(self, session, base_url):
    self.session = session
    self.base_url = base_url

 def quotes(self):

    symbols = input("\nPlease enter Stock Symbol: ")

    # URL for the API endpoint
    url = self.base_url + "/v1/market/quote/" + symbols + ".json"

    # Get the current time
    Hour    = int(datetime.now().strftime("%H"))

    #set previous price of stock to arbitrary variable at this time
    old_price  = float(0.0)
    ticker     = ""

    # Make API call for GET request
    response = self.session.get(url)

    if response is not None and response.status_code == 200:
        while Hour >= 9 and Hour <= 16:
            #print("")
            data = response.json()
            if data is not None and "QuoteResponse" in data and "QuoteData" in data["QuoteResponse"]:
                for quote in data["QuoteResponse"]["QuoteData"]:
                    if quote is not None and "Product" in quote and "symbol" in quote["Product"]:
                        ticker = quote["Product"]["symbol"]
                    if quote is not None and "All" in quote and "lastTrade" in quote["All"]:   
                        new_price = quote["All"]["lastTrade"]
                        if new_price != old_price:
                            #call function to send ticker and price to cpp class for processing
                            Processor.print(ticker,new_price)
                            old_price = new_price
                response = self.session.get(url)                
            else:
                # Handle errors
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

