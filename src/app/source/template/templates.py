import requests


def temp_headers(auth: str):
    auth_list = auth.split("&")
    headers = {
        "accept": "*/*",
        "accept-language": "ru-RU",
        "authorization": f"OAuth {auth_list[0]}",
        'client-id': 'kimne78kx3ncx6brgo4mv6wki5h1ko',
        'client-integrity': '',
        'client-session-id': '',
        'client-version': 'cfa6de7d-a3d8-4fbe-9182-65e8bdd07a8d',
        "content-type": "text/plain;charset=UTF-8",
        "origin": "https://www.twitch.tv",
        "referer": "https://www.twitch.tv/",
        "sec-ch-ua": '"Opera GX";v="109", "Not:A-Brand";v="8", "Chromium";v="123"',
        "sec-ch-ua-mobile": "?0",
        "sec-ch-ua-platform": '"Windows"',
        "sec-fetch-dest": "empty",
        "sec-fetch-mode": "cors",
        "sec-fetch-site": "same-site",
        "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36 OPR/109.0.0.0",
        "x-device-id": "hpVvuVNGTkDey1hxg1Sd2OtnGJJbFwmW",
    }
    return headers


def temp_data_message(channel_id: str, paste: str):
    data = (
        '{"operationName":"sendChatMessage","variables":{"input":{"channelID":"'
        + channel_id
        + '","message":"'
        + paste
        + '","nonce":"f404bf1b2867d0dc4afa8a35d91829ed","replyParentMessageID":null}},"extensions":{"persistedQuery":{"version":1,"sha256Hash":"0435464292cf380ed4b3d905e4edcb73078362e82c06367a5b2181c76c822fa2"}}}'
    ).encode()
    return data


def temp_data_sub(channel_id: str):
    # data = (
    #     '[{"operationName":"FollowButton_FollowUser","variables":{"input":{"disableNotifications":false,"targetID":"'
    #     + channel_id
    #     + '"}},"extensions":{"persistedQuery":{"version":1,"sha256Hash":"800e7346bdf7e5278a3c1d3f21b2b56e2639928f86815677a7126b093b2fdd08"}}},{"operationName":"AvailableEmotesForChannelPaginated","variables":{"channelID":"'
    #     + channel_id
    #     + '","withOwner":true,"pageLimit":350},"extensions":{"persistedQuery":{"version":1,"sha256Hash":"6c45e0ecaa823cc7db3ecdd1502af2223c775bdcfb0f18a3a0ce9a0b7db8ef6c"}}}]'
    data = ('[{"operationName":"FollowButton_FollowUser","variables":{"input":{"disableNotifications":false,"targetID":"'+channel_id +
            '"}},"extensions":{"persistedQuery":{"version":1,"sha256Hash":"800e7346bdf7e5278a3c1d3f21b2b56e2639928f86815677a7126b093b2fdd08"}}},{"operationName":"AvailableEmotesForChannelPaginated","variables":{"channelID":"'+channel_id +
            '","withOwner":true,"pageLimit":350},"extensions":{"persistedQuery":{"version":1,"sha256Hash":"6c45e0ecaa823cc7db3ecdd1502af2223c775bdcfb0f18a3a0ce9a0b7db8ef6c"}}}]').encode()
    return data
