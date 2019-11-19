#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
int n, m, pre[N], nex[N], cnt, ans[N];
bool vis1[N], mark[N];
queue<int> q;
vector<int> G[N];
inline void Delete(int u) {
    nex[pre[u]] = nex[u];  pre[nex[u]] = pre[u];
    ++ans[cnt], mark[u]=true;
}
inline void bfs(int u){
    ++cnt;
    q.push(u);
    Delete(u);
    while(!q.empty())
    {
        u = q.front();  q.pop();
        for(auto to : G[u])
            if(!mark[to]) vis1[to]=true;
        for(int i=nex[0]; i; i=nex[i])
            if(!vis1[i]) q.push(i), Delete(i);
        for(auto to : G[u])
            if(!mark[to]) vis1[to]=false;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++) pre[i]=i-1, nex[i]=i+1;
    pre[1]=0, nex[n]=0, nex[0]=1;
    int u, v;
    for(int i=1;i<=m;i++){
        scanf("%d%d", &u, &v);
        G[u].push_back(v);G[v].push_back(u);
    }
    u = 0;
    while(nex[u]) {
        mark[nex[u]] = true;
        bfs(nex[u]);
        u = 0;
    }
    cout<<cnt-1;
    return 0;
}