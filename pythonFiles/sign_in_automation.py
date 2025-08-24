from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager

def automate_sign_in(authorize_url):
    chrome_options = Options()
    chrome_options.add_argument("--headless")
    chrome_options.add_argument("--no-sandbox")
    chrome_options.add_argument("--disable-dev-shm-usage")

    driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=chrome_options)

    driver.get(authorize_url)

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

    # Locate the send code button, this is only needed once for broswser verification 
    #if "sendOTPCodeBtn" in driver.page_source:  
    send_code_button = driver.find_element(By.ID, "sendOTPCodeBtn")
    send_code_button.click()
    # Wait for the page to load after sign-in
    driver.implicitly_wait(30)


    # Locate the accept agreement button
    accept_button = driver.find_element(By.ID, "acceptSubmit")
    accept_button.click()

    # Wait for the page to load after accepting the agreement
    driver.implicitly_wait(5)

    '''
    # Get the verification code input field
    verification_code_input = driver.find_element(By.CSS_SELECTOR, "input[type*='value']")

    #driver.quit()

    return verification_code_input
    '''
