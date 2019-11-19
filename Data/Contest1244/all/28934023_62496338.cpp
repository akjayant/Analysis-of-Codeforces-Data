#include <iostream>
#include <vector> 
#include <queue>

#define MAXN 100011

using namespace std;

int N,A[3][MAXN],LEAF;
vector<vector<int> > edge(MAXN);
int COLOR[4][4][MAXN],parent[MAXN];
bool SEEN[MAXN];
void bfs(int CL1,int CL2){
    for (int i=1;i<=N;i++){
        parent[i]=0;
        SEEN[i]=false;
    }
    COLOR[CL1][CL2][LEAF]=CL1;COLOR[CL1][CL2][edge[LEAF][0]]=CL2;
    parent[edge[LEAF][0]]=LEAF;
    SEEN[LEAF]=true;SEEN[edge[LEAF][0]]=true;
    queue<int> QE;
    QE.push(edge[LEAF][0]);
    while (!QE.empty()){
        int X=QE.front();
        QE.pop();
        for (int i:edge[X])
            if (!SEEN[i]){
                parent[i]=X;
                SEEN[i]=true;
                QE.push(i);
                COLOR[CL1][CL2][i]=3-COLOR[CL1][CL2][parent[i]]-COLOR[CL1][CL2][parent[parent[i]]];
            }
    }
}
int main(){
    cin >> N;
    for (int i=1;i<=N;i++)
        cin >> A[0][i];
    for (int i=1;i<=N;i++)
        cin >> A[1][i];
    for (int i=1;i<=N;i++)
        cin >> A[2][i];
    int u,v;
    for (int i=1;i<N;i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i=1;i<=N;i++)
        if (edge[i].size()>2){
            cout << -1;
            exit(0);
        }
    else if (edge[i].size()==1) LEAF=i;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (i!=j)
                bfs(i,j);
    long long MINCOST=1e18,COST,Cx,Cy;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++) if (i!=j){
            COST=0;
            for (int k=1;k<=N;k++)
                COST+=A[COLOR[i][j][k]][k];
            if (COST<MINCOST){
                MINCOST=COST;
                Cx=i;Cy=j;
            }
        }
    cout << MINCOST << endl;
    for (int k=1;k<=N;k++)
        cout << COLOR[Cx][Cy][k]+1 << " ";
}