from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager

def automate_sign_in(authorize_url):
    # Set up Chrome options for headless browsing(uncomment to run in headless mode)
    chrome_options = Options()
    #chrome_options.add_argument('--no-sandbox')
    #chrome_options.add_argument('--headless=new')
    #chrome_options.add_argument("--window-size=1920,1080")
    #chrome_options.add_argument('--disable-dev-shm-usage')

    # install the ChromeDriver and create a new instance of the Chrome browser
    driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=chrome_options)

    # open the external browser and navigate to the authorize_url
    driver.get(authorize_url)

    driver.implicitly_wait(10)

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
    send_code_button = driver.find_element(By.ID, "sendOTPCodeBtn")
    
    try:
        # if the browser is already verified this step can be skipped
        if len(send_code_button) > 0:
            send_code_button.click()
            # Wait for the page to load after sign-in
            driver.implicitly_wait(40)
        else:
            driver.implicitly_wait(5)

    # exception handling if any error occurs
    except Exception as e:
        print(f"An error occurred: {e}")   
    
    # Locate the accept agreement button
    accept_button = driver.find_element(By.ID, "acceptSubmit")
    driver.get_screenshot_as_file("screenshot.png")
    accept_button.click()

    # Wait for the page to load after accepting the agreement
    driver.implicitly_wait(5)


    # Get the verification code input field
    verification_code_input_attr = driver.find_element(By.CSS_SELECTOR, "input[type='text']")
    verification_code_input = verification_code_input_attr.get_attribute("value")

    # Wait for a few seconds to ensure all actions are completed
    driver.implicitly_wait(10)
   
    # Close the browser
    driver.quit()

    # Return the verification code input
    return verification_code_input


    
    
