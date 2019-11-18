import sys
import xml.etree.ElementTree as ET

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

filename = "../Data/Contest1245/all_xml/29563152_64004391.xml"
tree = ET.parse(filename)
root = tree.getroot()
tokens = []
structure = simplify_xml_ast(root, tokens)
print(tokens)
print(structure)
