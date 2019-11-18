import os
import sys
from pathlib import Path
import random

random.seed(0)

f = open('../stats_china_group_hm_list.txt', 'r')
china_hm_data = f.readlines()
f.close()

f = open('../stats_china_group_lm_list.txt', 'r')
china_lm_data = f.readlines()
f.close()

f = open('../stats_row_group_lm_list.txt', 'r')
RoW_lm_data = f.readlines()
f.close()

f = open('../stats_row_group_hm_list.txt', 'r')
RoW_hm_data = f.readlines()
f.close()

random.shuffle(china_hm_data)
random.shuffle(china_lm_data)
random.shuffle(RoW_hm_data)
random.shuffle(RoW_lm_data)

contest_Dir = "./Contest1245"
os.makedirs(contest_Dir, exist_ok=True)

china_Dir = contest_Dir + "/China"
os.makedirs(china_Dir, exist_ok=True)

RoW_Dir = contest_Dir + "/RoW"
os.makedirs(RoW_Dir, exist_ok=True)

os.makedirs(RoW_Dir+"/hm", exist_ok=True)
os.makedirs(RoW_Dir+"/lm", exist_ok=True)
os.makedirs(china_Dir+"/hm", exist_ok=True)
os.makedirs(china_Dir+"/lm", exist_ok=True)

for i in range(10,20):
        file = RoW_hm_data[i].split(',')[1].split('.')[0]
        filePath = Path("../Data/Contest1245/all/"+file+".cpp")
        if not filePath.is_file():
            print(filePath)
        else:
            stream = os.popen('g++ -E '+str(filePath)+' -o '+RoW_Dir+"/hm/"+file+'.cpp')
            output = stream.read()
            print(output)

        file = RoW_lm_data[i].split(',')[1].split('.')[0]
        filePath = Path("../Data/Contest1245/all/"+file+".cpp")
        if not filePath.is_file():
            print(filePath)
        else:
            stream = os.popen('g++ -E '+str(filePath)+' -o '+RoW_Dir+"/lm/"+file+'.cpp')
            output = stream.read()
            print(output)

        file = china_hm_data[i].split(',')[1].split('.')[0]
        filePath = Path("../Data/Contest1245/all/"+file+".cpp")
        if not filePath.is_file():
            print(filePath)
        else:
            stream = os.popen('g++ -E '+str(filePath)+' -o '+china_Dir+"/hm/"+file+'.cpp')
            output = stream.read()
            print(output)

        file = china_lm_data[i].split(',')[1].split('.')[0]
        filePath = Path("../Data/Contest1245/all/"+file+".cpp")
        if not filePath.is_file():
            print(filePath)
        else:
            stream = os.popen('g++ -E '+str(filePath)+' -o '+china_Dir+"/lm/"+file+'.cpp')
            output = stream.read()
            print(output)
