from SeleniumScrap import SeleniumScrap
from SeleniumScrap import By

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
    return chanell_id


print(get_channel_id("baxadoto"))
