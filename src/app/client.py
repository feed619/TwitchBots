import requests

# url = 'http://127.0.0.1:5000/api/sent_data'
url = 'http://127.0.0.1:5000/api/get_id'


# data = {'channel': 'Golovach top data Golovach '
data = {'channel': 'Golovach'}
# }

response = requests.post(url, json=data)
print(response.json())
