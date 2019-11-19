#!/usr/bin/env python
# coding: utf-8

import pandas as pd
import numpy as np
import zss    #pip install zss
import xml.etree.ElementTree as ET
import os
import sys


def get_children(node):
    my_children = [child for child in node]
    return my_children

    
def get_label(node):
    my_label = [child.tag for child in node]
    return my_label

def xmltree_dist(root_1,root_2):
    if root_1==root_2:
        return 0.0
    else:
        d  = zss.simple_distance(root_1,root_2,get_children,get_label)
    return d

def compute_parse_trees(region,f_names):
    parsed_ast = []
    #f_names =[]
    for file in f_names:
        
        xml_1 = './DataAnalysis/Contest1245/'+str(region)+'/all/'+str(file)
        parsed_ast.append(ET.parse(xml_1).getroot())
    return parsed_ast


#computes similarity matrix
def similarity_xml_tree_dist(f_s,labels,p,q):
    similarity = {}
    for i in range(p,q):
        for j in range(len(f_s)):
            #f_s[i] = str(f_s[i])
            #f_s[j] = str(f_s[j])
            
            if labels[i] in similarity.keys():
            	similarity[labels[i]].append(xmltree_dist(f_s[i],f_s[j]))
            else:
                similarity[labels[i]] = [xmltree_dist(f_s[i],f_s[j])]
            print(str(i)+","+str(j)+" done!")
        print(str(i+1)+" out of "+str(len(f_s))+" files done!")
    similarity_matrix = pd.DataFrame.from_dict(similarity,orient='index',columns=labels) 
    return similarity_matrix

#sys.argv[0] = file_name, [1] = list of file names(.txt) [2]=region ([3]=row start of dist matrix computation [4] = row end) - Parallel computation code
print(sys.argv)
l=[]
f = open(str(sys.argv[1]), "r")
s = f.read()
l = s.split(" ")
f.close()
l.remove('')
print(sys.argv)
parsed_ast = compute_parse_trees(sys.argv[2],l)
sim = similarity_xml_tree_dist(parsed_ast,l,int(sys.argv[3]),int(sys.argv[4]))

sim.to_csv("similarity_matrix_"+str(sys.argv[2])+"_"+str(sys.argv[3])+"_to_"+str(sys.argv[4])+".csv")




