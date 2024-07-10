import subprocess
import ctypes
import sys
import time
import pyautogui


# Function to check and install Windows updates
def check_and_install_windows_updates():
    try:
        print("Checking and installing Windows updates...")
        subprocess.run(['powershell', 'Install-Module PSWindowsUpdate -Force -AllowClobber'], shell=True)
        result = subprocess.run(['powershell', 'Import-Module PSWindowsUpdate; Get-WindowsUpdate -Install -AcceptAll'], capture_output=True, text=True, shell=True)
        updates = result.stdout.splitlines()
        if updates:
            print("Found Windows updates:")
            for update in updates:
                print(update)
        else:
            print("No Windows updates found.")
    except Exception as e:
        print(f"An error occurred while checking and installing Windows updates: {e}")

# Function to upgrade installed packages using 'winget'
def upgrade_packages_with_winget():
    try:
        print("Upgrading installed packages with winget...")
        subprocess.run(['cmd.exe', '/c', 'winget', 'upgrade', '--all'], shell=True)
    except Exception as e:
        print(f"An error occurred while upgrading installed packages with winget: {e}")


# Function to open Microsoft Store and check for updates
def check_and_install_store_updates():
    print("Checking and installing updates from Microsoft Store...")
    try:
        # Open Microsoft Store
        subprocess.run(['powershell', 'Start-Process', 'ms-windows-store://pdp/?productid=9WZDNCRFJBMP'], shell=True)

        # Wait for Microsoft Store to open
        print("Waiting for Microsoft Store to open...")
        time.sleep(5)

        # Use pyautogui to simulate key presses
        pyautogui.hotkey('ctrl', 'l')  # Focus on the address bar
        pyautogui.write('ms-windows-store://library')  # Type the URL for the Library tab
        pyautogui.press('enter')  # Press Enter to go to the Library tab

        # Wait for the Library tab to open
        print("Waiting for Library tab to open...")
        time.sleep(5)

        # Use pyautogui to simulate key presses
        pyautogui.hotkey('alt', 'u')  # Press Alt + U to trigger "Get updates"

        print("Microsoft Store updates checked and installed.")
    except Exception as e:
        print(f"An error occurred while checking and installing updates from Microsoft Store: {e}")


# Function to check and install updates for Razer applications using Razer Central
def check_and_install_razer_updates():
    print("Checking and installing updates for Razer applications...")
    try:
        # Open Razer Central (use a more generic approach)
        subprocess.run(['powershell', 'Start-Process', 'RazerCentral.exe'], shell=True)

        # Wait for Razer Central to open
        print("Waiting for Razer Central to open...")
        time.sleep(10)  # Adjust the time based on your system's performance and Razer Central's startup time

        # Use pyautogui to simulate key presses (these are just examples, you need to adapt them based on Razer Central's UI)
        pyautogui.click(x=100, y=100)  # Click on a hypothetical "Check for updates" button
        # I need help locating it...

        print("Razer updates checked and installed.")
    except Exception as e:
        print(f"An error occurred while checking and installing updates for Razer applications: {e}")


# Wait for user input before closing the terminal
def wait_for_exit():
    input("Press Enter to exit...")


# Check if the script is running with administrative privileges
def is_admin():
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except:
        return False

# Main function
def main():
    if is_admin():
        check_and_install_windows_updates()
        upgrade_packages_with_winget()
        check_and_install_store_updates()
        # check_and_install_razer_updates() not correct

        # Wait for user input before closing the terminal
        wait_for_exit()
    else:
        ctypes.windll.shell32.ShellExecuteW(None, "runas", sys.executable, " ".join(sys.argv), None, 1)

if __name__ == "__main__":
    main()

"""
Apps to be added:
- Firefox
- Spotify
- Steam
- WPD
- Discord
- Pycharm
- Avira

--Optional
--Mods for lethal comany in thunderstore
"""