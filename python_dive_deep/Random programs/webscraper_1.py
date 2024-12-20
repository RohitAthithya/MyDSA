from pathlib import Path
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.desired_capabilities import DesiredCapabilities
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# Dummy website URL (replace with the actual URL)
website_url = "https://www.colorado.edu/ecee/research"

# Set up the Selenium WebDriver (using Chrome in this case)
service = Service(
    str(
        Path(
            r"C:\Users\ADMIN\Downloads\chromedriver-win64\chromedriver-win64\chromedriver.exe"
        )
    )
)  # Replace with the path to your chromedriver
options = webdriver.ChromeOptions()

# Initialize the driver
driver = webdriver.Chrome(service=service, options=options)

try:
    # Open the website
    driver.get(website_url)

    # Wait for the elements to be present
    wait = WebDriverWait(driver, 10)
    elements = wait.until(
        EC.presence_of_all_elements_located(
            (By.XPATH, "//div[contains(@class, 'grid-card')]//strong")
        )
    )

    # Collect all text content from the matched elements
    strong_texts = [element.text for element in elements]

    # Print the collected texts
    for text in strong_texts:
        print(text)

finally:
    # Close the driver
    driver.quit()
