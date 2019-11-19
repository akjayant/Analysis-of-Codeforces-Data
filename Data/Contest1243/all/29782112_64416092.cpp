#include <bits/stdc++.h>
using namespace std;
set<int> G[400010];
set<int> g1;
int vis[400010];
int par[400010];
int n,m;

int find(int x) {
	if (par[x]==x) return par[x];
	else return par[x]=find(par[x]);
}

void bfs(int s) {
    queue<int> que;
    que.push(s);
    for(int i = 1;i <= n;i++) {
        if(i != s) g1.insert(i);
    }
    set<int> del;
    while(que.size()) {
        int now = que.front();
        que.pop();
        del.clear();
        for(set<int>::iterator it=g1.begin();it!=g1.end();++it) {
            if(!G[now].count(*it)) {
                par[find(now)] = find(*it);
                del.insert(*it);
                que.push(*it);
            }
        }
        for(set<int>::iterator it=del.begin();it!=del.end();++it) {
            g1.erase(*it);
        }
    }
}

map<int, int> mapp;
int main(){
    scanf("%d%d",&n,&m);
    for(int i =1;i<=n;i++) {
        par[i]=i;
    }
    
    for(int i = 1;i<=m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].insert(v);
        G[v].insert(u);
    }
    
    for(int i=1;i<=n;i++) {
        if(par[i]==i) {
            bfs(i);
        }
    }
    
    for(int i=1;i<=n;i++) {
        mapp[par[i]]++;
    }
    int len=mapp.size();
    printf("%d\n",len-1);
    return 0;
}