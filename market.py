import json
import time
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
    now = datetime.now()
    dt_string_Hour    = int(now.strftime("%H"))

    # Make API call for GET request
    while dt_string_Hour >= 9 and dt_string_Hour <= 16:
        response = self.session.get(url)

        if response is not None and response.status_code == 200:

            parsed = json.loads(response.text)

            # Handle and parse response
            print("")
            data = response.json()
            if data is not None and "QuoteResponse" in data and "QuoteData" in data["QuoteResponse"]:
                for quote in data["QuoteResponse"]["QuoteData"]:
                    if quote is not None and "Product" in quote and "symbol" in quote["Product"]:
                        print("Symbol: " + quote["Product"]["symbol"])
                        ticker = quote["Product"]["symbol"]
                    if quote is not None and "All" in quote and "lastTrade" in quote["All"]:
                        print("Last Price: " + str(quote["All"]["lastTrade"]))
                        price = quote["Product"]["symbol"]
                        Stock_info = [ticker, price]
                        time.sleep(10)
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
            break

 #def send_info(Stock_info):
