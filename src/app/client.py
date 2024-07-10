import requests

url = 'http://127.0.0.1:5000/sent_data'
data = {'data': 'Golovach top data Golovach top '}

response = requests.post(url, json=data)
print(response.json())
