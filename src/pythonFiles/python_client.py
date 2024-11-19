'''
NB: This python script is owned and distributed by E*trade, some modifications have been made by the author to tailor this script for my use case.
This script auithenticates user credenials using oauth1.
User credentials are passed to the script from  config.ini.
Once authentication is successful a base_url and a session is generated using the user credentials.
main_menu() is then executed with the base_url and session information and the market script is called, refer to: /src/pythonFiles/market/market.py
'''

from __future__ import print_function
import webbrowser
import configparser
from rauth import OAuth1Service
from market.market import Market

#loading configuration file
config = configparser.ConfigParser()
#refer to .gitignore for this file. This file contains keys for authentication. NB Each user should have unique keys.
config.read('config.ini')

def oauth():
    """Allows user authorization for the sample application with OAuth 1"""
    etrade = OAuth1Service(
        name="etrade",
        consumer_key=config["DEFAULT"]["CONSUMER_KEY"],
        consumer_secret=config["DEFAULT"]["CONSUMER_SECRET"],
        request_token_url="https://api.etrade.com/oauth/request_token",
        access_token_url="https://api.etrade.com/oauth/access_token",
        authorize_url="https://us.etrade.com/e/t/etws/authorize?key={}&token={}",
        base_url="https://api.etrade.com")

    base_url = config["DEFAULT"]["PROD_BASE_URL"]


    # Step 1: Get OAuth 1 request token and secret.
    request_token, request_token_secret = etrade.get_request_token(params={"oauth_callback": "oob", "format": "json"})

    # Step 2: Go through the authentication flow. Login to E*TRADE.
    # After you login, the page will provide a verification code to enter.
    authorize_url = etrade.authorize_url.format(etrade.consumer_key, request_token)
    webbrowser.open(authorize_url)
    text_code = input("Please accept agreement and enter verification code from browser: ")

    # Step 3: Exchange the authorized request token for an authenticated OAuth 1 session
    session = etrade.get_auth_session(request_token,request_token_secret,params={"oauth_verifier": text_code})
    #print(str(session))

    main_menu(session, base_url)

# main_menu will instantiate the Market class from: /src/pythonFiles/market/market.py and pass session and base_url information to mkt.quotes. 
def main_menu(session, base_url):
    mkt = Market(session, base_url)
    mkt.quotes()
       
# main function which calls oauth() to begin executing the script.
if __name__ == "__main__":
    oauth()
