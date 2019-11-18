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

### plot histogram for program time + memory
# problemIndex = 3
# program_time = []
# program_memory = []
#
# for l in statistic_data:
#     entries = l.split('\t')
#     language = entries[5+4*(problemIndex-1)]
#     time = (entries[4+4*(problemIndex-1)].split(' ')[0])
#     memory = (entries[3+4*(problemIndex-1)].split(' ')[0])
#     if "c++" in language.lower():
#         if time != '-':
#             program_time.append(int(time))
#             program_memory.append(int(memory))
#
# plt.hist(program_time, bins = 200)
# plt.show()
#
# plt.hist(program_memory, bins = 100)
# plt.show()

### plot histogram for country evaluation
# countryNames = []
# countryContestants = []
# startPosition = 1
# endPosition = 1000
#
# for i in range(startPosition, endPosition+1):
#     entries = statistic_data[i].split('\t')
#     country = entries[2]
#     if country != '-':
#         if country not in countryNames:
#             countryNames.append(country)
#             countryContestants.append(0)
#         index = countryNames.index(country)
#         countryContestants[index] += 1
#
# print(countryNames)
# print(countryContestants)
#
# y_pos = np.arange(len(countryNames))
# plt.bar(y_pos, countryContestants)
# plt.xticks(y_pos, countryNames, fontsize=4)
# plt.savefig('standingsAll_country.pdf')

### distrbution analysis of memory + time for 'China'
countryNames = []
countryContestants = []

problemIndex = 3
program_time = []
program_memory = []

startPosition = 1
endPosition = 1000

group1 = 0
group2 = 0

for i in range(startPosition, endPosition+1):
    entries = statistic_data[i].split('\t')
    country = entries[2]
    if country != 'China' and country != '-':
        language = entries[6+4*(problemIndex-1)]
        time = (entries[5+4*(problemIndex-1)].split(' ')[0])
        memory = (entries[4+4*(problemIndex-1)].split(' ')[0])
        if "c++" in language.lower():
            if time != '-':
                if(int(memory)) <= 1000:
                    group1 += 1
                else:
                    group2 += 1

                program_time.append(int(time))
                program_memory.append(int(memory))

print(group1, group2)

plt.hist(program_time, bins = 200)
plt.show()

plt.hist(program_memory, bins = 100)
plt.xticks(np.arange(0,60000,1000), fontsize=4)
plt.show()
