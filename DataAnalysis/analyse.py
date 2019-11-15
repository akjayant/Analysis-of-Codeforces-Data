import os
import sys
import numpy as np
import matplotlib.pyplot as plt

### preprocess data for contest 1245
contest_id = "1245"
statistic_files = "../Data/Contest"+contest_id+"/standings_statistics.csv"

f = open(statistic_files,'r')
statistic_data = f.readlines()
f.close()

problemIndex = 3
program_time = []
program_memory = []

for l in statistic_data:
    entries = l.split('\t')
    language = entries[5+4*(problemIndex-1)]
    time = (entries[4+4*(problemIndex-1)].split(' ')[0])
    memory = (entries[3+4*(problemIndex-1)].split(' ')[0])
    if "c++" in language.lower():
        if time != '-':
            program_time.append(int(time))
            program_memory.append(int(memory))

plt.hist(program_time, bins = 200)
plt.show()

plt.hist(program_memory, bins = 100)
plt.show()
