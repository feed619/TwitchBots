
import requests
from SeleniumScrap import SeleniumScrap
from SeleniumScrap import By
import pyautogui
import time


def add_account(username: str, password: str) -> str:
    scrap = SeleniumScrap()
    scrap.set_url(
        "https://www.twitch.tv/")
    time.sleep(5)

    login_box = scrap.get_driver().find_elements(
        By.XPATH, '/html/body/div[1]/div/div[1]/nav/div/div[3]/div[3]/div/div[1]/div[1]/button/div/div')
    login_box[0].click()

    time.sleep(5)

    user_name_box = scrap.get_driver().find_elements(
        By.XPATH, "/html/body/div[3]/div/div/div/div/div/div[1]/div/div/div/div[2]/form/div/div[1]/div/div[2]/div/input")
    user_name_box[0].click()
    time.sleep(5)

    pyautogui.write('rsload.net')
    # user_name_box[0].send_keys(username)
    time.sleep(5)

    password_box = scrap.get_driver().find_elements(
        By.XPATH, "/html/body/div[3]/div/div/div/div/div/div[1]/div/div/div/div[2]/form/div/div[2]/div/div[1]/div[2]/div[1]/div/input")
    password_box[0].click()
    time.sleep(5)

    pyautogui.write('rsload.net')
    # password_box[0].send_keys(password)
    time.sleep(5)

    pyautogui.press('enter')
    time.sleep(15)

    # enter_box = scrap.get_driver().find_elements(
    #     By.XPATH, "/html/body/div[3]/div/div/div/div/div/div[1]/div/div/div/div[2]/form/div/div[3]/div/button/div/div")
    # enter_box[0].click()
    # time.sleep(10)

    # if chanell_id == "User not found..":
    #     return "none"
    # return chanell_id


headers = {
    'accept': '*/*',
    'accept-language': 'ru-RU',

    'authorization': 'OAuth tnou992rlkgmjzhvxmchh34ug9vxk0',

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

data = '{"operationName":"sendChatMessage","variables":{"input":{"channelID":"87186401","message":"есть кто ?","nonce":"f404bf1b2867d0dc4afa8a35d91829ed","replyParentMessageID":null}},"extensions":{"persistedQuery":{"version":1,"sha256Hash":"0435464292cf380ed4b3d905e4edcb73078362e82c06367a5b2181c76c822fa2"}}}'.encode()

response = requests.post('https://gql.twitch.tv/gql',
                         headers=headers, data=data)
