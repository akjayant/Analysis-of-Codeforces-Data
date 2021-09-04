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
import lightgbm as lgb

def vectorize(contest, model):
    df = OrderedDict()
    file_class =[]
    path = '../Data/'+str(contest)+'/standings_statistics.csv'
    print("path",path)
    csv = pd.read_csv(path,sep='\t')
    China_participants = np.array(csv.loc[(csv['Country']=='China'),['ParticipantID']])
    China_participants = [str(i[0]) for i in China_participants]
    India_participants = np.array(csv.loc[(csv['Country']=='Индия',['ParticipantID'])])
    India_participants =  [str(i[0]) for i in India_participants]
    p_flag=[]
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
        if participant_id in China_participants:
            class_dict[i]=0
            d2v_dict[i] = model.infer_vector(f_xml_list)
        elif participant_id in India_participants:
            class_dict[i]=1
            d2v_dict[i] = model.infer_vector(f_xml_list)



        #print(df)
    d2v_df = pd.DataFrame.from_dict(d2v_dict,orient='index')
    d2v_df['fp_key'] = d2v_df.index
    print(d2v_df.shape)
    class_df = pd.DataFrame.from_dict(class_dict,orient='index')
    class_df['fp_key'] = class_df.index
    print(class_df.shape)
    df = pd.merge(d2v_df,class_df,on='fp_key')
    return df

def threshold(x):
    labels=[]
    for i in x:
        if i>=.55:
            labels.append(1)
        else:
            labels.append(0)
    return labels


def light_gbm_model(data_train,labels_train,data_test,labels_test):
    d_train = lgb.Dataset(data_train, label=labels_train)
    params = {}
    params['learning_rate'] = 0.003
    params['boosting_type'] = 'gbdt'
    params['objective'] = 'binary'
    params['metric'] = 'binary_logloss'
    params['sub_feature'] = 0.5
    params['num_leaves'] = 40
    params['min_data'] = 50
    params['max_depth'] = 50
    params['is_unbalance'] = True
    #params['class_weight']=class_weight
    clf = lgb.train(params, d_train, 1000)


    print("Training accuracy-")
    print(accuracy_score(labels_train,threshold(clf.predict(data_train))))
    print("Testing accuracy-")
    print(accuracy_score(labels_test,threshold(clf.predict(data_test))))
    print("Confusion matrix -")
    print(confusion_matrix(labels_test,threshold(clf.predict(data_test))))
    #('true negatives is C[0,0] , false negatives is C[1,0] , true positives is C[1,1]  and false positives is C[0,1]')
    # print("Precision and recall - ")
    # print(precision_score(labels_test,threshold(clf.predict(data_test))))
    # print(recall_score(labels_test,threshold(clf.predict(data_test))))
    print("f score - ")
    print(f1_score(labels_test,threshold(clf.predict(data_test)),average='weighted'))



def log_reg_model(data_train,labels_train,data_test,labels_test):

    log_reg = LogisticRegression()

    log_reg.fit(data_train,labels_train)
    print("Training accuracy-")
    print(accuracy_score(labels_train,log_reg.predict(data_train)))
    print("Testing accuracy-")
    print(accuracy_score(labels_test,log_reg.predict(data_test)))
    print("Confusion matrix -")
    print(confusion_matrix(labels_test,log_reg.predict(data_test)))
    print("f1-score - ")
    print(f1_score(labels_test,log_reg.predict(data_test),average='weighted'))





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
n_class=2
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.4, random_state=42)
#class_weight=compute_class_weight('balanced', [0,1], y_train)
# cw_dict = {}
# for i in range(len(class_weight)):
#     cw_dict[i] = class_weight[i]
print("LogisticRegression Model Results")
log_reg_model(x_train,y_train,x_test,y_test)

print("Lightgbm Model results")
light_gbm_model(x_train,y_train,x_test,y_test)
