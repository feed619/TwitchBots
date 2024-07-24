import time

import pyautogui
import requests
from SeleniumScrap import By, SeleniumScrap


def add_account(username: str, password: str) -> str:
    scrap = SeleniumScrap()
    scrap.set_url("https://www.twitch.tv/")
    time.sleep(5)

    login_box = scrap.get_driver().find_elements(
        By.XPATH,
        "/html/body/div[1]/div/div[1]/nav/div/div[3]/div[3]/div/div[1]/div[1]/button/div/div",
    )
    login_box[0].click()

    time.sleep(5)

    user_name_box = scrap.get_driver().find_elements(
        By.XPATH,
        "/html/body/div[3]/div/div/div/div/div/div[1]/div/div/div/div[2]/form/div/div[1]/div/div[2]/div/input",
    )
    user_name_box[0].click()
    time.sleep(5)

    pyautogui.write("rsload.net")
    # user_name_box[0].send_keys(username)
    time.sleep(5)

    password_box = scrap.get_driver().find_elements(
        By.XPATH,
        "/html/body/div[3]/div/div/div/div/div/div[1]/div/div/div/div[2]/form/div/div[2]/div/div[1]/div[2]/div[1]/div/input",
    )
    password_box[0].click()
    time.sleep(5)

    pyautogui.write("rsload.net")
    # password_box[0].send_keys(password)
    time.sleep(5)

    pyautogui.press("enter")
    time.sleep(15)
