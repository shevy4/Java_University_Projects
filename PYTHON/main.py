import time
import random
from selenium.webdriver.common.by import By
from selenium import webdriver
from selenium.webdriver.chrome.service import Service

service = Service(executable_path="chromedriver.exe")
driver = webdriver.Chrome(service=service)

# Open the Google Form URL
driver.get("https://docs.google.com/forms/")

time.sleep(3)

grocery_items = ["apples", "bananas", "oranges", "milk", "bread", "eggs", "cheese", "tomatoes", "potatoes", "onions"]

for _ in range(5):
    # Get all question elements
    question_elements = driver.find_elements(By.XPATH, "//div[@role='listitem']")

    # Iterate through each question and choose a random option
    try:
        for question in question_elements:
            options = question.find_elements(By.XPATH, ".//div[@role='radio']")
            random_option = random.choice(options)
            random_option.click()
    except IndexError:
        text_area_input = driver.find_element(By.XPATH, "//textarea")
        text_area_input.send_keys(random.choice(grocery_items))

    time.sleep(2)
    submit_button = driver.find_element(By.XPATH, "//span[text()='Submit']")
    submit_button.click()

    time.sleep(3)  # Adding a delay to ensure the page fully loads before clicking on "Submit another response"
    submit_another_button = driver.find_element(By.LINK_TEXT, 'Submit another response')
    submit_another_button.click()

driver.quit()
