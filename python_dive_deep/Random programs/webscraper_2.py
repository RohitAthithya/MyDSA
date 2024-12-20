import requests
from lxml import html

# Dummy URL
url = r"https://www.colorado.edu/ecee/research"

# Send a GET request to the webpage
response = requests.get(url)

# Parse the HTML content of the webpage
tree = html.fromstring(response.content)

# Use XPath to extract the desired text
text_elements = tree.xpath("//div[contains(@class, 'grid-card')]//strong/text()")

# Print the extracted text
for text in text_elements:
    print(text)
