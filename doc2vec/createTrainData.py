import os
from os import listdir
from os.path import isfile, join
import random
random.seed(0)

data = []

for i in ["1245", "1236", "1243", "1244", "1248"]:
    contest_dir = "../Data/Contest"+i
    onlyfiles = [f for f in listdir(contest_dir+"/all_xml_simplified/") if isfile(join(contest_dir+"/all_xml_simplified", f)) and "simplified" not in f]

    for f in onlyfiles:
        fr = open(contest_dir+"/all_xml_simplified/"+f, 'r')
        data.append(fr.read())
        fr.close()

random.shuffle(data)
fw = open('data.txt', 'w')
for d in data:
    fw.write(d)
fw.close()
