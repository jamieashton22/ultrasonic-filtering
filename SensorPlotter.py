# Code for serial plotter

# ----- MODULES ----------------------------------------------------

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
import sys
import serial
import serial.tools.list_ports
import time
import re
from collections import deque

# --------- SERIALPLOTTER CLASS ---------------------------------

class SerialPlotter: 

    def __init__(self, ax, twidth):                                     # ax - axis object where line will be plotted, twidth - length of time window for x axis
       
        self.ax = ax
        self.twidth = twidth

        # self.tdata = [0] # to hold time values
        # self.ydata = [0] # to hold sensor values


        # trying with deque
        self.tdata = deque(maxlen=1000)
        self.ydata1 = deque(maxlen=1000)
        self.ydata2 = deque(maxlen=1000)

        self.line1 = Line2D(self.tdata, self.ydata1, color='blue', label='Unfiltered', linewidth = 1)
        self.line2 = Line2D(self.tdata, self.ydata2, color='red', label='Filtered', linewidth = 1)
        self.ax.add_line(self.line1)
        self.ax.add_line(self.line2)
        self.ax.set_ylim(0, 100)      # add y limits
        self.ax.set_xlim(0 ,self.twidth)
        

    def update(self, y1, y2, t):            # method to add a y-value to the plot and update it 

        self.tdata.append(t)
        self.ydata1.append(y1)
        self.ydata2.append(y2)
        self.line1.set_data(self.tdata, self.ydata1)
        self.line2.set_data(self.tdata, self.ydata2)

        if (self.tdata[-1]) < self.twidth:
            self.ax.set_xlim(0,self.twidth)
        else:
            self.ax.set_xlim((self.tdata[-1])-self.twidth, self.tdata[-1])

        # max_y = max(self.ydata1[-1], self.ydata2[-1])         #USE THIS FOR DYNAMIC SCROLLING ON Y
        # self.ax.set_ylim(0, max_y + 10)

        self.ax.set_ylim(0,10)                                  #USE THIS FOR FIXED VIEW

        return self.line1, self.line2

# -------- SELECTING AND OPENING SERIAL PORT ------------------------------------------------

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()
port = ''
portList = []

print("\n List of available ports \n")
for onePort in ports:
    portList.append(str(onePort.device))
    print(str(onePort))

port = input("\n select port \n")

if port not in portList:
    print("Invalid port chosen")
    sys.exit(1)

print("\n Port selected: ")
print(port)

# OPEN PORT

#get baud rate from user
chosenBaud = input("\n select baud rate \n")
serialInst.baudrate = chosenBaud

serialInst.port = port
serialInst.open()
print("\n port open \n")

# -------- MAIN ------------------------------------------------

fig, ax = plt.subplots()
plotter = SerialPlotter(ax, 10)
ax.set_xlabel("Time (s)")
ax.set_ylabel("Distance (cm)")
ax.grid(True, linestyle='--', alpha=0.5)
ax.legend(loc='upper left', fontsize=10)

start_time = time.time()

try:
    while True:

        if serialInst.in_waiting:

            current_time = time.time()
            time_elapsed = current_time - start_time        # get t values for x axis

            data_raw = serialInst.readline()
            data_strip = data_raw.decode('utf-8').rstrip()
            sensor_reading = re.findall(r"\d*\.\d+|\d+", data_strip)
            
            plotter.update(float(sensor_reading[0]), float(sensor_reading[1]),time_elapsed)
            plt.pause(0.01)

    
except KeyboardInterrupt:
    print(" Exiting")

finally:
    serialInst.close()
        
        