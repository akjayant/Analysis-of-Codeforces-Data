#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
set<int>g[100010],f;

void bfs(int x){
    queue<int>q;
    q.push(x);
    while(!q.empty()){
        int t=q.front();q.pop();
        vector<int>d;
        for (int i:f)
            if (!g[t].count(i)){
                d.push_back(i);q.push(i);
            }
        for (int i:d)f.erase(i);
    }
    
}

int main(){
	scanf("%d%d",&n,&m);
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        g[x].insert(y);
        g[y].insert(x);
    }
    for (int i=1;i<=n;i++)f.insert(i);
    int ans=-1;
    for (int i=1;i<=n;i++)
        if (f.count(i)){
            f.erase(i);ans++;bfs(i);
    }
    printf("%d\n",ans);
}
