import typing

import selenium  # type: ignore
from fake_useragent import UserAgent  # type: ignore
from selenium import webdriver  # type: ignore
from selenium.webdriver.common.by import By

Options = typing.Union[webdriver.firefox, webdriver.chrome]
Driver = typing.Optional[selenium.webdriver]


class SeleniumScrap:
    __asd = 0
    a = 0
    __options_default: list[str] = [
        f"--user-agent={UserAgent().random}",
        "--disable-blink-features=AutomationControlled",
        # "--headless",
        "--disable-gpu",
        "--no-sandbox",
        "--disable-dev-shm-usage",
        # "--remote-debugging-port=9222"
        # "--proxy-server=217.29.63.40:13675"
    ]
    __driver: Driver

    _user_agent: str = ""
    _proxy: dict
    _optionsF: Options
    _optionsCh: Options
    _url: str = ""

    def __init__(self, options: list[str] = __options_default, browser_Chrome=True):
        if browser_Chrome:
            SeleniumScrap.Create_Chrome_driver(self, options)
        else:
            SeleniumScrap.Create_Firefox_driver(self, options)

    def Create_Chrome_driver(self, options: list[str] = None):
        self._optionsCh: Options = webdriver.ChromeOptions()
        if options:
            for str_option in options:
                self._optionsCh.add_argument(str_option)
        self.__driver = webdriver.Chrome(options=self._optionsCh)

    def Create_Firefox_driver(self, _options: list[str] = None):
        self._optionsF: Options = webdriver.FirefoxOptions()
        if _options:
            for str_option in _options:
                self._optionsF.add_argument(str_option)
        self.__driver = webdriver.Firefox(options=self._optionsF)

    def set_url(self, url: str) -> None:
        self._url = url
        self.__driver.get(url=url)

    def get_url(self) -> str:
        return self._url

    def run(self) -> None:
        self.__driver.get(url=self._url)

    def get_driver(self) -> Driver:
        return self.__driver

    def __call__(self, url: str = "", *args: typing.Any, **kwds: typing.Any) -> typing.Any:
        self._url = url
        self.__driver.get(url=url)

    def __del__(self):
        self.__driver.close()
        self.__driver.quit()
