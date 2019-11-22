import sys
import os
from os import listdir
from os.path import isfile, join
import gensim.models as g
import scipy
import numpy as np
import progressbar

#parameters
model="model"+str(sys.argv[1])+".bin"

#inference hyper-parameters
start_alpha=0.01
infer_epoch=400

#load model
m = g.Doc2Vec.load(model)

for i in ["1245", "1236", "1243", "1244", "1248"]:
    contest_dir = "../Data/Contest"+i
    onlyfiles = [f for f in listdir(contest_dir+"/all_xml_simplified/") if isfile(join(contest_dir+"/all_xml_simplified", f)) and "simplified" not in f]

    bar = progressbar.ProgressBar(max_value=len(onlyfiles))
    files_processed = 0

    str_data = ""
    for f in onlyfiles:
        fr = open(contest_dir+"/all_xml_simplified/"+f, 'r')
        data = fr.read().split('\n')[0]
        fr.close()
        data = data.strip().split()
        v = m.infer_vector(data, alpha=start_alpha, steps=infer_epoch).tolist()
        v_string = ' '.join([str(elem) for elem in v])
        str_data = str_data + f+"\t"+v_string+"\n"

        files_processed += 1
        bar.update(files_processed)

    fw = open(contest_dir+"/doc2vec_embedding_model_"+str(sys.argv[1])+".txt", 'w')
    fw.write(str_data)
    fw.close()

    print(contest_dir)
