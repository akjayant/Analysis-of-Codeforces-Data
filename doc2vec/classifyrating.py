import gensim.models as g
import codecs
from scipy import spatial
import os
import pandas as pd
import numpy as np
from sklearn.cluster import KMeans
from collections import OrderedDict
from sklearn.linear_model import LogisticRegression
from sklearn.utils.class_weight import compute_class_weight
from sklearn.metrics import accuracy_score,confusion_matrix, f1_score
from sklearn import preprocessing
from sklearn.model_selection import train_test_split


def vectorize(contest, model):
    df = OrderedDict()
    file_class =[]
    path = '../Data/'+str(contest)+'/standings_statistics.csv'
    print("path",path)
    csv = pd.read_csv(path,sep='\t')
    # csv = csv[["ParticipantID","Problem1_id"]]
    # print(csv.head())
    #--xml_dict = { key= fileid+problem_id, value = doc2vec(file)}
    d2v_dict={}
    class_dict={}
    count=0
    for i in os.listdir('../Data/'+str(contest)+'/all_xml_simplified/'):
        f_xml_string = open('../Data/'+str(contest)+'/all_xml_simplified/'+str(i),'r').read()
        f_xml_list = f_xml_string.strip().split()
        file_id = str(i).strip('.xml').split("_")[1]
        participant_id = str(i).strip('.xml').split("_")[0]
        file_id = str(file_id)
        participant_id = str(participant_id)
        if np.array(csv.loc[csv['ParticipantID'].astype(str)==participant_id,['Color']]=='blue')[0][0]:
            class_dict[i]=0
            d2v_dict[i]=model.infer_vector(f_xml_list)
        elif np.array(csv.loc[csv['ParticipantID'].astype(str)==participant_id,['Color']]=='violet')[0][0]:
            class_dict[i]=1
            d2v_dict[i] = model.infer_vector(f_xml_list)
        else:
            class_dict[i]=1
            d2v_dict[i] = model.infer_vector(f_xml_list)
        count+=1


        #print(df)
    d2v_df = pd.DataFrame.from_dict(d2v_dict,orient='index')
    d2v_df['fp_key'] = d2v_df.index
    class_df = pd.DataFrame.from_dict(class_dict,orient='index')
    class_df['fp_key'] = class_df.index
    df = pd.merge(d2v_df,class_df,on='fp_key')
    return df

#parameters
model="model100.bin"
#inference hyper-parameters
start_alpha=0.01
infer_epoch=1000
#load model
model = g.Doc2Vec.load(model)
contest = "Contest1244"
data = vectorize(contest,model)
print(data.shape)
x = data.iloc[:,:100]
y = data['0_y']
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.4, random_state=42)


clf = LogisticRegression(random_state=0).fit(x_train, y_train)

y_pred = clf.predict(x_test)
print("accuracy_score=",accuracy_score(y_pred,y_test))
print("confusion_matrix=", confusion_matrix(y_pred,y_test))
print("F1 scores=",f1_score(y_test,y_pred,average=weighted))
