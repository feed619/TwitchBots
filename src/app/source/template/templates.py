def temp_headers(auth_token: str):
    headers = {
        'accept': '*/*',
        'accept-language': 'ru-RU',
        'authorization': f'OAuth {auth_token}',
        'content-type': 'text/plain;charset=UTF-8',
        'origin': 'https://www.twitch.tv',
        'referer': 'https://www.twitch.tv/',
        'sec-ch-ua': '"Opera GX";v="109", "Not:A-Brand";v="8", "Chromium";v="123"',
        'sec-ch-ua-mobile': '?0',
        'sec-ch-ua-platform': '"Windows"',
        'sec-fetch-dest': 'empty',
        'sec-fetch-mode': 'cors',
        'sec-fetch-site': 'same-site',
        'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36 OPR/109.0.0.0',
        'x-device-id': 'hpVvuVNGTkDey1hxg1Sd2OtnGJJbFwmW',
    }
    return headers


def temp_data_message(channel_id: str, paste: str):
    data = ('{"operationName":"sendChatMessage","variables":{"input":{"channelID":"'+channel_id+'","message":"'+paste +
            '","nonce":"f404bf1b2867d0dc4afa8a35d91829ed","replyParentMessageID":null}},"extensions":{"persistedQuery":{"version":1,"sha256Hash":"0435464292cf380ed4b3d905e4edcb73078362e82c06367a5b2181c76c822fa2"}}}').encode()
    return data
