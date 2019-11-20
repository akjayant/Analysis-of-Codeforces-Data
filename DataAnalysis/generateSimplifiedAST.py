import sys
import xml.etree.ElementTree as ET
import os
from os import listdir
from os.path import isfile, join
import operator

def simplifyTag(tag):
    return tag.split('}')[1]

def simplify_xml_ast(xmlroot, tokens):
    if xmlroot.text != None:
        token = xmlroot.text.lstrip().rstrip()
        if token != "":
            tokens.append(token)

    if simplifyTag(xmlroot.tag) == "unit":
        structure = ""
    else:
        structure = simplifyTag(xmlroot.tag)
        for a in xmlroot.attrib:
            structure = structure + " " + a + " " + xmlroot.attrib[a]
        structure += " "

    children_processed = False
    for child in xmlroot:
        children_processed = True
        child_structure = simplify_xml_ast(child, tokens)
        structure += child_structure

        if child.tail != None:
            token = child.tail.lstrip().rstrip()
            if token != "":
                tokens.append(token)

    if children_processed:
        structure += ("finished ")

    return structure

total = 0
tokenDictionary = dict()

for i in ["1245", "1236", "1243", "1244", "1248"]:
    contest_dir = "../Data/Contest"+i
    onlyfiles = [f for f in listdir(contest_dir+"/all_xml") if isfile(join(contest_dir+"/all_xml", f)) and "simplified" not in f]
    os.makedirs(contest_dir+"/all_xml_simplified", exist_ok=True)

    for f in onlyfiles:
        tree = ET.parse(contest_dir+"/all_xml/"+f)
        root = tree.getroot()
        tokens = []
        structure = simplify_xml_ast(root, tokens)

        fw = open(contest_dir+"/all_xml_simplified/"+f, 'w')
        fw.write(structure+"\n")
        fw.close()

        for t in tokens:
            if t not in tokenDictionary:
                tokenDictionary[t] = 0
            tokenDictionary[t] += 1
            total += 1
    print("Processed Contest "+i+" ...")

print(len(tokenDictionary), total)
sorted_x = sorted(tokenDictionary.items(), key=operator.itemgetter(1), reverse=True)

### we take the top k tokens
blacklist = [";", ",", "(", ")", "{", "}", "[", "]"]
k = 400
top_tokens = []
i = 0

while len(top_tokens) != k:
    if sorted_x[i][0] not in blacklist:
        top_tokens.append(sorted_x[i][0])
    i += 1
print(top_tokens)

for i in ["1245", "1236", "1243", "1244", "1248"]:
    contest_dir = "../Data/Contest"+i
    onlyfiles = [f for f in listdir(contest_dir+"/all_xml") if isfile(join(contest_dir+"/all_xml", f)) and "simplified" not in f]

    fw = open(contest_dir+"/tokens_stats.txt", 'w')
    for f in onlyfiles:
        tree = ET.parse(contest_dir+"/all_xml/"+f)
        root = tree.getroot()
        tokens = []
        structure = simplify_xml_ast(root, tokens)

        token_vector = [0]*k
        for t in tokens:
            if t in top_tokens:
                token_vector[top_tokens.index(t)] += 1

        line = f.split(".")[0]
        for t in token_vector:
            line = line + " " + str(t)
        fw.write(line+"\n")
    print("Processed Contest "+i+" ...")
    fw.close()
