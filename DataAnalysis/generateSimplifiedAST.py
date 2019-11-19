import sys
import xml.etree.ElementTree as ET
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

    for child in xmlroot:
        child_structure = simplify_xml_ast(child, tokens)
        structure += child_structure

        if child.tail != None:
            token = child.tail.lstrip().rstrip()
            if token != "":
                tokens.append(token)

    return structure

total = 0
tokenDictionary = dict()
contest_dir = "../Data/Contest1245/"
onlyfiles = [f for f in listdir(contest_dir+"/all_xml") if isfile(join(contest_dir+"/all_xml", f)) and "simplified" not in f]

for f in onlyfiles:
    tree = ET.parse(contest_dir+"/all_xml/"+f)
    root = tree.getroot()
    tokens = []
    structure = simplify_xml_ast(root, tokens)

    fw = open(contest_dir+"/all_xml/simplified_"+f, 'w')
    fw.write(structure+"\n")
    fw.close()

    for t in tokens:
        if t not in tokenDictionary:
            tokenDictionary[t] = 0
        tokenDictionary[t] += 1
        total += 1
    print("Processed "+f+" ...")

print(len(tokenDictionary), total)
sorted_x = sorted(tokenDictionary.items(), key=operator.itemgetter(1), reverse=True)

### we take the top 1000 tokens
blacklist = [";", ",", "(", ")", "{", "}", "[", "]"]
top100_tokens = []
i = 0

while len(top100_tokens) != 100:
    if sorted_x[i][0] not in blacklist:
        top100_tokens.append(sorted_x[i][0])
    i += 1
print(top100_tokens)

fw = open(contest_dir+"/tokens_stats.txt", 'w')
for f in onlyfiles:
    tree = ET.parse(contest_dir+"/all_xml/"+f)
    root = tree.getroot()
    tokens = []
    structure = simplify_xml_ast(root, tokens)

    token_vector = [0]*100
    for t in tokens:
        if t in top100_tokens:
            token_vector[top100_tokens.index(t)] += 1

    line = f.split(".")[0]
    for t in token_vector:
        line = line + " " + str(t)
    fw.write(line+"\n")
    print("Processed "+f+" ...")
fw.close()
