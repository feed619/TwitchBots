import ctypes
import subprocess
import asyncio
import sys
# import os
# os.system("& C:/Users/azimo/AppData/Local/Programs/Python/Python311/python.exe c:/Проекты/TwitchBots/build-widget-Desktop_Qt_6_6_3_MinGW_64_bit-Release/run.py")


def run_hidden_windows(command):
    startupinfo = subprocess.STARTUPINFO()
    startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
    startupinfo.wShowWindow = subprocess.SW_HIDE
    process = subprocess.Popen(command, startupinfo=startupinfo)
    return process


async def run_app(app_path):
    startupinfo = subprocess.STARTUPINFO()
    startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
    startupinfo.wShowWindow = subprocess.SW_HIDE

    await subprocess.Popen(['python', app_path], check=True, startupinfo=startupinfo)


async def run_widget(widget_path):
    startupinfo = subprocess.STARTUPINFO()
    startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
    startupinfo.wShowWindow = subprocess.SW_HIDE
    await subprocess.Popen([widget_path], check=True, startupinfo=startupinfo)


async def run_python_script_async(script_path):
    try:
        # Запуск Python-скрипта
        process = await asyncio.create_subprocess_exec('python', script_path,
                                                       stdout=asyncio.subprocess.PIPE,
                                                       stderr=asyncio.subprocess.PIPE)

        # Ожидание завершения процесса
        stdout, stderr = await process.communicate()

        # Получение кода завершения
        return_code = process.returncode

        # Печать вывода
        if stdout:
            print(f"Python script output:\n{stdout.decode()}")
        if stderr:
            print(f"Python script error:\n{stderr.decode()}")

        # Проверка кода завершения
        if return_code != 0:
            print(
                f"Error: Python script {script_path} exited with code {return_code}")
    except Exception as e:
        print(f"Error while running {script_path}: {e}")


async def run_exe_async(exe_path):
    try:
        # Запуск исполняемого файла
        process = await asyncio.create_subprocess_exec(exe_path,
                                                       stdout=asyncio.subprocess.PIPE,
                                                       stderr=asyncio.subprocess.PIPE)

        # Ожидание завершения процесса
        stdout, stderr = await process.communicate()

        # Получение кода завершения
        return_code = process.returncode

        # Печать вывода
        if stdout:
            print(f"EXE output:\n{stdout.decode()}")
        if stderr:
            print(f"EXE error:\n{stderr.decode()}")

        # Проверка кода завершения
        if return_code != 0:
            print(f"Error: EXE {exe_path} exited with code {return_code}")
    except Exception as e:
        print(f"Error while running {exe_path}: {e}")


async def main():
    # Укажите путь к вашему Python-скрипту здесь
    python_script_path = "../src/app/main.py"
    # Укажите путь к вашему исполняемому файлу здесь
    exe_path = "widget.exe"

    # Создание задач для асинхронного запуска
    tasks = [
        run_python_script_async(python_script_path),
        run_exe_async(exe_path)
    ]

    # Запуск задач и ожидание их завершения
    await asyncio.gather(*tasks)

if __name__ == "__main__":
    # if sys.platform == "win32":
    # ctypes.windll.user32.ShowWindow(
    #     ctypes.windll.kernel32.GetConsoleWindow(), 0)
    asyncio.run(main())
