import struct
import smbus
import time
sleep = 1
# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)
numb=1
# This is the address we setup in the Arduino Program
address = 0x8

print("enter ")
while numb==1:
    ledstate = input(">>>  ")
    if ledstate == "1":
        bus.write_byte(address, 0x1)
    elif ledstate == "0":
        bus.write_byte(address, 0x0)
    elif ledstate == "2":
        bus.write_byte(address, 0x2)
    elif ledstate == "3":
        bus.write_byte(address, 0x3)
    else:
        numb = 0