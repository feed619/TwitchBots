import subprocess
import asyncio


async def run_app(app_path):
    await subprocess.run(['python', app_path], check=True)


async def run_widget(widget_path):
    await subprocess.run([widget_path], check=True)


async def run_python_script_async(script_path):
    try:
        process = await asyncio.create_subprocess_exec('python', script_path,
                                                       stdout=asyncio.subprocess.PIPE,
                                                       stderr=asyncio.subprocess.PIPE)
        stdout, stderr = await process.communicate()
        return_code = process.returncode()

        if stdout:
            print(f"Python script output:\n{stdout.decode()}")
        if stderr:
            print(f"Python script error:\n{stdout.decode()}")
        if return_code != 0:
            print(
                f"Error: Python script {script_path} exited with code {return_code}")
    except Exception as e:
        print(f"Error while running {script_path}: {e}")


async def run_exe_async(exe_path):
    try:
        process = await asyncio.create_subprocess_exec(exe_path,
                                                       stdout=asyncio.subprocess.PIPE,
                                                       stderr=asyncio.subprocess.PIPE)
        stdout, stderr = await process.communicate()
        return_code = process.returncode()

        if stdout:
            print(f"EXE output:\n{stdout.decode()}")
        if stderr:
            print(f"EXE error:\n{stdout.decode()}")
        if return_code != 0:
            print(f"Error: EXE {exe_path} exited with code {return_code}")

    except Exception as e:
        print(f"Error while running {exe_path}: {e}")


async def main():
    python_script_path = "../src/app/main.py"
    exe_path = "widget.exe"

    taks = [
        run_python_script_async(python_script_path),
        run_exe_async(exe_path)
    ]

    await asyncio.run(*taks)

if __name__ == "__main__":
    asyncio.run(main())
