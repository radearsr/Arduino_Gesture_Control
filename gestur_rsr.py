import serial
import pyautogui

ArduinoSerial = serial.Serial('com14',9600)

while 1:
    incoming = str (ArduinoSerial.readline())
    print(incoming)
    if 'PAUSE/PLAY' in incoming:
        pyautogui.keyDown('space')
    if 'VolUp' in incoming:
        pyautogui.press('up')
    if 'VolDown' in incoming:
        pyautogui.press('down')
    if 'maju' in incoming:
        pyautogui.press('right')
    if 'mundur' in incoming:
        pyautogui.press('left')

    incoming = "";
