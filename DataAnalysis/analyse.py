import os
import sys
import numpy as np
import matplotlib.pyplot as plt
import operator

### preprocess data for contest 1245
contest_id = "1248"
statistic_files = "../Data/Contest"+contest_id+"/problem_statistics.csv"

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
countryCount = dict()
colorCount = dict()
problemCount = dict()
languageCount = dict()

for i in range(1, len(statistic_data)):
    entries = statistic_data[i].split('\t')

    country = entries[2]
    color = entries[3]
    problem = entries[1]
    language = entries[4]

    if language not in languageCount:
        languageCount[language] = 0
    languageCount[language] += 1

    if "c++" in language.lower():
        if problem not in problemCount:
            problemCount[problem] = 0
        problemCount[problem] += 1

        if color not in colorCount:
            colorCount[color] = 0
        colorCount[color] += 1

        if country not in countryCount:
            countryCount[country] = 0
        countryCount[country] += 1

print(languageCount)
sorted_x = sorted(languageCount.items(), key=operator.itemgetter(1), reverse=True)
x = []
y = []
for key in sorted_x:
    y.append(key[1])
    x.append(key[0])
plt.bar(np.arange(len(x)), y)
plt.xticks(np.arange(len(x)), x, fontsize=6)
plt.show()

print(problemCount)
sorted_x = sorted(problemCount.items(), key=operator.itemgetter(0))
x = []
y = []
for key in sorted_x:
    y.append(key[1])
    x.append(key[0])
plt.bar(np.arange(len(x)), y)
plt.xticks(np.arange(len(x)), x, fontsize=6)
plt.show()

print(colorCount)
sorted_x = sorted(colorCount.items(), key=operator.itemgetter(0))
x = []
y = []
for key in sorted_x:
    y.append(key[1])
    x.append(key[0])
plt.bar(np.arange(len(x)), y)
plt.xticks(np.arange(len(x)), x, fontsize=6)
plt.show()

print(countryCount)
sorted_x = sorted(countryCount.items(), key=operator.itemgetter(1), reverse=True)
x = []
y = []
for i in range(10):
    if sorted_x[i][0] != '-':
        y.append(sorted_x[i][1])
        x.append(sorted_x[i][0])
plt.bar(np.arange(len(x)), y)
plt.xticks(np.arange(len(x)), x, fontsize=6)
plt.show()


### distrbution analysis of memory + time for 'China'
# countryNames = []
# countryContestants = []
#
# problemIndex = 3
# program_time = []
# program_memory = []
#
# startPosition = 1
# endPosition = 1000
#
# group1 = 0
# group2 = 0
#
# for i in range(startPosition, endPosition+1):
#     entries = statistic_data[i].split('\t')
#     country = entries[2]
#     if country != 'China' and country != '-':
#         language = entries[6+4*(problemIndex-1)]
#         time = (entries[5+4*(problemIndex-1)].split(' ')[0])
#         memory = (entries[4+4*(problemIndex-1)].split(' ')[0])
#         if "c++" in language.lower():
#             if time != '-':
#                 if(int(memory)) <= 1000:
#                     group1 += 1
#                 else:
#                     group2 += 1
#
#                 program_time.append(int(time))
#                 program_memory.append(int(memory))
#
# print(group1, group2)
#
# plt.hist(program_time, bins = 200)
# plt.show()
#
# plt.hist(program_memory, bins = 100)
# plt.xticks(np.arange(0,60000,1000), fontsize=4)
# plt.show()
