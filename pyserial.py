#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 28 21:05:08 2018

@author: aman
"""

import serial
import time

ArduinoSerial=serial.Serial('/dev/cu.usbmodem1421',9600)
time.sleep(2)
while True:
        print(ArduinoSerial.readline())