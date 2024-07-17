import requests
from source.SeleniumScrap import SeleniumScrap
from source.SeleniumScrap import By

import time


def get_channel_id(channel_name: str) -> str:
    scrap = SeleniumScrap()
    scrap.set_url(
        "https://www.streamweasels.com/tools/convert-twitch-username-to-user-id/")
    input_box = scrap.get_driver().find_elements(
        By.XPATH, '/html/body/div[1]/div/div/main/article/div/div/form/fieldset[1]/input')
    input_box[0].send_keys(channel_name)
    send_put = scrap.get_driver().find_elements(
        By.XPATH, "/html/body/div[1]/div/div/main/article/div/div/form/fieldset[1]/button")
    send_put[0].click()
    time.sleep(2)
    channel_id_box = scrap.get_driver().find_elements(
        By.XPATH, "/html/body/div[1]/div/div/main/article/div/div/form/fieldset[2]/span")
    chanell_id = channel_id_box[0].text

    if chanell_id == "User not found..":
        return "none"
    return chanell_id


# print(get_channel_id("baxadoto"))

# import requests

# cookies = {
#     'cf_clearance': 'lP7.euWC3YRzv7LdIl.avdELwqJR1uloAvZze1byv5Q-1721132731-1.0.1.1-5stVvrMJ1iMRG5_3JSmHRQqsnwzeHh1V_jIqjPXSv4X56bT4m7u6TBNMXaUmjAR2x5aiX5Ptggsx9RbH_8LlSA',
#     '__ga_r2t4L95': 'eyJpdiI6IkRnNVo3RDI2aGMvS1p6NGZVbjlSSFE9PSIsInZhbHVlIjoiNDJCWnpiOTh5SEIvQlUzWnNSSnNxb0Y1VEcvanR3alVBY25RUGFPWFluTmNMWm9VNTE2ZXRiai9uemNHT3J4MkM5Q2ljL21rbnZNUGx4Vzg2OG5QS0pQcDNhd2F1Tm9lVUQxQThnMk5wcm89IiwibWFjIjoiMGRjOGRlYjJhYzhhYzM3ZjRmMWYzNGJkZmVmNjE5NGQzNjU1YTZmYmRjOThhZjdlNGRmMTYwYWI4NDc4NGY2ZCIsInRhZyI6IiJ9',
#     '_gid': 'GA1.2.1841000835.1721132869',
#     '_ga': 'GA1.2.1577523775.1721058979',
#     '_gat_gtag_UA_88777325_16': '1',
#     '_ga_EWRXQ5LP6S': 'GS1.1.1721132730.3.1.1721133132.11.0.0',
#     'XSRF-TOKEN': 'eyJpdiI6ImxKRy9RUDZaNHVRcks2YUxoOU9zTmc9PSIsInZhbHVlIjoiaW51U1FxY3lDS1BySzJ2Qm9Ta1AvQW5ZUTBGenJockFHZ0RSRFRBU25ZZCtoMnZEcmlPQmxZT2Rnc1lJSlRjU3ltRmRTVEZnN3JONytpVTM5OFpsdjJib3ViQ3h2aVE5bk56NGhxWlYxUFA0L0N2K1pITVFRV3hZL0REWVlhRUsiLCJtYWMiOiI5Zjg2ODNiZjU3M2Y4ZDQ5ZjkzMTdhZjVkMjcyNWMyYTVlYmUyNzVlODkzMGIzZThmMWUwNjY5YjEzMTIwM2M4IiwidGFnIjoiIn0%3D',
#     'esc_partner_panel_session': 'eyJpdiI6Im15ZWtxU0gyNGFhdXVZd2VEYmw2VlE9PSIsInZhbHVlIjoiS2dQakphZzBpSHRVZ2hTblpuN3VkRzJxMHNOdXArNUJLNlllVkpYMWRLVEVwM3Bab2dZck11d0xKZHpsb2FTM3RKaW9aSVZwSENwUkxoMFF6OVBxczVuSE9nVzgzREZIS05RUmpSa2xqcUczaFZRQWVhY2dkeE1uVGVnWFdod3MiLCJtYWMiOiI1YzNkNWQyNmYxZmZmMWQxZGI3MTY3OTU5ZmI1NzQ0NzM3M2QzZjg5ZjY2MGQ5MTYxY2Q3MTlhYzAzNGViNTFmIiwidGFnIjoiIn0%3D',
# }

# headers = {
#     'accept': 'text/html, application/xhtml+xml',
#     'accept-language': 'ru-RU,ru;q=0.9,en-US;q=0.8,en;q=0.7',
#     'content-type': 'application/json',
#     # 'cookie': 'cf_clearance=lP7.euWC3YRzv7LdIl.avdELwqJR1uloAvZze1byv5Q-1721132731-1.0.1.1-5stVvrMJ1iMRG5_3JSmHRQqsnwzeHh1V_jIqjPXSv4X56bT4m7u6TBNMXaUmjAR2x5aiX5Ptggsx9RbH_8LlSA; __ga_r2t4L95=eyJpdiI6IkRnNVo3RDI2aGMvS1p6NGZVbjlSSFE9PSIsInZhbHVlIjoiNDJCWnpiOTh5SEIvQlUzWnNSSnNxb0Y1VEcvanR3alVBY25RUGFPWFluTmNMWm9VNTE2ZXRiai9uemNHT3J4MkM5Q2ljL21rbnZNUGx4Vzg2OG5QS0pQcDNhd2F1Tm9lVUQxQThnMk5wcm89IiwibWFjIjoiMGRjOGRlYjJhYzhhYzM3ZjRmMWYzNGJkZmVmNjE5NGQzNjU1YTZmYmRjOThhZjdlNGRmMTYwYWI4NDc4NGY2ZCIsInRhZyI6IiJ9; _gid=GA1.2.1841000835.1721132869; _ga=GA1.2.1577523775.1721058979; _gat_gtag_UA_88777325_16=1; _ga_EWRXQ5LP6S=GS1.1.1721132730.3.1.1721133132.11.0.0; XSRF-TOKEN=eyJpdiI6ImxKRy9RUDZaNHVRcks2YUxoOU9zTmc9PSIsInZhbHVlIjoiaW51U1FxY3lDS1BySzJ2Qm9Ta1AvQW5ZUTBGenJockFHZ0RSRFRBU25ZZCtoMnZEcmlPQmxZT2Rnc1lJSlRjU3ltRmRTVEZnN3JONytpVTM5OFpsdjJib3ViQ3h2aVE5bk56NGhxWlYxUFA0L0N2K1pITVFRV3hZL0REWVlhRUsiLCJtYWMiOiI5Zjg2ODNiZjU3M2Y4ZDQ5ZjkzMTdhZjVkMjcyNWMyYTVlYmUyNzVlODkzMGIzZThmMWUwNjY5YjEzMTIwM2M4IiwidGFnIjoiIn0%3D; esc_partner_panel_session=eyJpdiI6Im15ZWtxU0gyNGFhdXVZd2VEYmw2VlE9PSIsInZhbHVlIjoiS2dQakphZzBpSHRVZ2hTblpuN3VkRzJxMHNOdXArNUJLNlllVkpYMWRLVEVwM3Bab2dZck11d0xKZHpsb2FTM3RKaW9aSVZwSENwUkxoMFF6OVBxczVuSE9nVzgzREZIS05RUmpSa2xqcUczaFZRQWVhY2dkeE1uVGVnWFdod3MiLCJtYWMiOiI1YzNkNWQyNmYxZmZmMWQxZGI3MTY3OTU5ZmI1NzQ0NzM3M2QzZjg5ZjY2MGQ5MTYxY2Q3MTlhYzAzNGViNTFmIiwidGFnIjoiIn0%3D',
#     'origin': 'https://streamscharts.com',
#     'referer': 'https://streamscharts.com/tools/convert-username?login=1721132820',
#     'sec-ch-ua': '"Opera GX";v="109", "Not:A-Brand";v="8", "Chromium";v="123"',
#     'sec-ch-ua-arch': '"x86"',
#     'sec-ch-ua-bitness': '"64"',
#     'sec-ch-ua-full-version': '"109.0.5097.142"',
#     'sec-ch-ua-full-version-list': '"Opera GX";v="109.0.5097.142", "Not:A-Brand";v="8.0.0.0", "Chromium";v="123.0.6312.124"',
#     'sec-ch-ua-mobile': '?0',
#     'sec-ch-ua-model': '""',
#     'sec-ch-ua-platform': '"Windows"',
#     'sec-ch-ua-platform-version': '"10.0.0"',
#     'sec-fetch-dest': 'empty',
#     'sec-fetch-mode': 'cors',
#     'sec-fetch-site': 'same-origin',
#     'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36 OPR/109.0.0.0',
#     'x-csrf-token': 'jGf4IprLkDO7qzF2lYw37Ochd3lfgLzY89CPHsEQ',
#     'x-livewire': 'true',
# }

# json_data = {
#     'username': 'baxadoto',

# }

# response = requests.post(
#     'https://streamscharts.com/livewire/message/sc.convert-username.convert-block',
#     cookies=cookies,
#     headers=headers,
#     json=json_data,
# )

# Note: json_data will not be serialized by requests
# exactly as it was in the original request.
# data = '{"fingerprint":{"id":"GNy2bbr9uNJmSYDCxABP","name":"sc.convert-username.convert-block","locale":"en","path":"tools/convert-username","method":"GET","v":"acj"},"serverMemo":{"children":[],"errors":[],"htmlHash":"700b150d","data":{"guestLock":false,"allowedPlatforms":[1,2,37,29,62,35,45],"selectedPlatformId":1,"username":"baxadot","channelId":null,"platform":{"id":1,"slug":"twitch","name":"Twitch","link":"https://twitch.tv/","recap_hashtag":"#StreamsRecap","color":"145, 71, 255","hasFollowers":true,"parseDate":"2018-01-01 00:00:00","parseDateForGame":"2019-07-01 00:00:00","titlesAnalytics":true,"languages":true},"channel":null,"error":null,"searchedBy":"channel_name","ytPrefix":"handle","ytPrefixes":[{"name":"username","prefix":"youtube.com/c/","label":"/c/"},{"name":"handle","prefix":"youtube.com/","label":"@"},{"name":"legacy","prefix":"youtube.com/user/","label":"/user/"}]},"dataMeta":[],"checksum":"52dcde787313c920ca5fecfe351494b3ea1060d1daf00f447702c8937fc83552"},"updates":[{"type":"syncInput","payload":{"id":"nyw1","name":"username","value":"baxado"}}]}'
# response = requests.post(
#    'https://streamscharts.com/livewire/message/sc.convert-username.convert-block',
#    cookies=cookies,
#    headers=headers,
#    data=data,
# )

# print(response.text)
