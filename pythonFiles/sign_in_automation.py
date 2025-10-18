from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager

def automate_sign_in(authorize_url):
    # Set up Chrome options for headless browsing(uncomment to run in headless mode)
    chrome_options = Options()
    chrome_options.add_argument('--no-sandbox')
    #chrome_options.add_argument('--headless=new')
    chrome_options.add_argument("--window-size=1920,1080")
    chrome_options.add_argument('--disable-dev-shm-usage')
    chrome_options.add_argument("--disable-gpu")
    chrome_options.add_argument("--disable-renderer-backgrounding")
    chrome_options.add_argument("--disable-background-timer-throttling")
    chrome_options.add_argument("--disable-backgrounding-occluded-windows")
    

    # install the ChromeDriver and create a new instance of the Chrome browser
    driver = webdriver.Chrome(options=chrome_options)

    # open the external browser and navigate to the authorize_url
    driver.get(authorize_url)
    # Wait for the page to load
    driver.implicitly_wait(5)

    # Locate the username and password fields and sign in button
    user_input = driver.find_element(By.ID, "USER")
    password_input = driver.find_element(By.ID, "password")
    sign_in_button = driver.find_element(By.ID, "mfaLogonButton")

    user_input.send_keys("") # Enter with your username 
    password_input.send_keys("") # Enter with your password
    sign_in_button.click() 

    # Wait for the page to load after sign-in
    driver.implicitly_wait(5)

    # Locate send OTP code button 
    sendOTPCodeBtn_elements = driver.find_elements(By.ID, "sendOTPCodeBtn")
    
    # if the browser is already verified this step can be skipped
    if len(sendOTPCodeBtn_elements) > 0:
        # Click the send code button to send the MFA code to your device
        driver.find_element(By.ID, "sendOTPCodeBtn").click()
        # Wait for the page to load after sending the code
        driver.implicitly_wait(20)
        # Prompt the user to enter the MFA code received on their device
        mfa_code = input("Please enter mfa verification code from your device: ")
        # Locate the verification code input field and submit button
        verification_box = driver.find_element(By.ID, "verificationCode")
        # Enter the MFA code
        verification_box.send_keys(mfa_code)
        #driver.implicitly_wait(10)
        # select radio button to not remember the browser NB: you can choose to remember the browser if you wish
        remember_browser_radio = driver.find_element(By.ID, "doNotSaveDevice")
        # Click the radio button to not remember the browser
        remember_browser_radio.click()
        # Locate and click the submit button
        submit_code_button = driver.find_element(By.CSS_SELECTOR, ".vertical-offset-md.btn.btn-block.btn-lg.btn-primary")
        # Click the submit button to complete the sign-in process
        submit_code_button.click()
        # Wait for the page to load after sign-in
        driver.implicitly_wait(5)      
    else:
        print("Browser already verified, proceeding to next step...")
        driver.implicitly_wait(5) 
    
    
    # Locate the accept agreement button
    accept_button = driver.find_element(By.ID, "acceptSubmit")
    # Click the accept agreement button to accept the terms
    accept_button.click()

    # Wait for the page to load after accepting the agreement
    driver.implicitly_wait(5)


    # Get the verification code input field
    verification_code_input_attr = driver.find_element(By.CSS_SELECTOR, "input[type='text']")
    verification_code_input = verification_code_input_attr.get_attribute("value")

    # Wait for a few seconds to ensure all actions are completed
    driver.implicitly_wait(5)
   

    # Close the browser
    driver.quit()

    # Return the verification code input
    return verification_code_input


    
    
