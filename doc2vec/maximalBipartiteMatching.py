import networkx as nx

G = nx.Graph()
for i in range(numWorkers): # combine comment and people
    for j in range(numWorkers):
        edgeWeight = 0
        for s in personWorkerMap[i]:
            for d in commentWorkerMap[j]:
                edgeWeight += edgeCount[s][d]
        G.add_edge(i,j+numWorkers,weight=edgeWeight)

personCommentMatching = list(nx.max_weight_matching(G,maxcardinality=True))
print(personCommentMatching, len(personCommentMatching))
