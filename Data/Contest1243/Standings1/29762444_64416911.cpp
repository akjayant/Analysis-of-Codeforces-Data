#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> G[100005];
vector<int> V;
int us[100005];
set<int> s;
set<int>::iterator it;
queue<int> que;
void bfs(int u){
    us[u]=1;
    while(!que.empty()) que.pop();
    que.push(u);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        V.clear();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(s.find(v)!=s.end()){
                V.push_back(v);
                s.erase(v);
            }
        }
        for(it=s.begin();it!=s.end();it++){
            int v=(*it);
            if(us[v]==1) continue;
            us[v]=1;
            que.push(v);
        }
        s.clear();
        for(int i=0;i<V.size();i++) s.insert(V[i]);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int num=0;
    for(int i=1;i<=n;i++){
        if(us[i]==0){
            num++;
            for(int j=1;j<=n;j++) s.insert(j);
            /*for(int j=0;j<G[i].size();j++){
                int v=G[i][j];
                s.insert(v);
            }*/
            bfs(i);
        }
    }
    printf("%d\n",num-1);
    return 0;
}
