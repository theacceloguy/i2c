
import sys
import smbus2 as smbus#,smbus2
import time

I2C_SLAVE_ADDRESS = 0x04

while True :
    I2Cbus = smbus.SMBus(1)
    with smbus.SMBus(1) as I2Cbus:
        while True:
            try:
                data=I2Cbus.read_i2c_block_data(0x04,0x00,2)
                data1=int(data[0])
                data2=int(data[1])
                print(data1)
                print(data2)
                time.sleep(1)
            except:
                print("remote i/o error")
                time.sleep(0.5)

