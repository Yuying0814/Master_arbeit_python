import time

import serial

port = serial.Serial("COM6", 1200)
port.close()

time.sleep(3)