import time

import requests
from source.template.templates import temp_data_message, temp_data_sub, temp_headers


def send_message(
    accounts: dict, channel_id: str, paste: str, sleep: int, sub: bool, split: bool
):
    status_code_list: list = []
    if split:
        index = 0
        paste_list = paste.split("^")
        len_paste_list = len(paste_list)
        len_accounts = len(accounts)
        paste_list = paste_list * int((len_accounts / len_paste_list) + 1)

    for acc in accounts:
        headers = temp_headers(acc.get("token"))
        if split:
            data = temp_data_message(channel_id, paste_list[index])
            index += 1
        else:
            data = temp_data_message(channel_id, paste)
        response = requests.post(
            "https://gql.twitch.tv/gql", headers=headers, data=data
        )

        status_code_acc = {
            "name": acc.get("name"),
            "status_code": response.json()
            .get("data")
            .get("sendChatMessage")
            .get("dropReason"),
        }
        if sub and (status_code_acc.get("status_code") == "FOLLOWERS_ONLY"):
            # print("tyt")
            data = temp_data_sub(channel_id)
            response = requests.post(
                "https://gql.twitch.tv/gql", headers=headers, data=data
            )
            status_code_acc["status_code"] = "R9K_DONE"

        status_code_list.append(status_code_acc)
        time.sleep(sleep)
    return status_code_list


# {"data": {"sendChatMessage": {"dropReason": null, "message": {"id": "5b4df5d1-0c2c-42cb-9344-b740719ff9e4", "__typename": "ChatMessage"},
#                               "__typename": "SendChatMessagePayload"}}, "extensions": {"durationMilliseconds": 85, "operationName": "sendChatMessage", "requestID": "01J324PNXVKEB6CPZVHDVR1BTP"}}
# {"data": {"sendChatMessage": {"dropReason": "R9K_MODE", "message": null, "__typename": "SendChatMessagePayload"}},
#     "extensions": {"durationMilliseconds": 79, "operationName": "sendChatMessage", "requestID": "01J324PPEX9KY6GX9CHTDTS1NW"}}
