import time
import requests
from source.template.templates import temp_data_message, temp_headers


def send_message(accounts: dict, channel_id: str, paste: str, sleep: int):
    for acc in accounts:
        print(acc.get("name"))
        print(acc.get("token"))

        headers = temp_headers(acc.get("token"))
        data = temp_data_message(channel_id, paste)
        response = requests.post('https://gql.twitch.tv/gql',
                                 headers=headers, data=data)

        time.sleep(sleep)
