import numpy as np
import matplotlib.pyplot as plt

data = []

#
with open("battery_data.csv", "r") as f:
    for line in f:
        if (line != "\n"):
            temp = line.strip().split(",")
            time = float(temp[0])
            voltage = float(temp[1])

            data_temp = [time, voltage]
            data.append(data_temp)


data = np.array(data)
time = data[:,0]
voltage = data[:,1]

plt.figure(figsize=(10,6), dpi=150)
plt.scatter(time, voltage, marker='.', color='k', s=45)
plt.ylim([13,14])
plt.grid()
plt.ylabel("Battery Voltage (V)")
plt.xlabel("Elapsed Time (s)")
plt.title("Battery Voltage vs Time")
plt.savefig("battery_plot.svg")
plt.show()
