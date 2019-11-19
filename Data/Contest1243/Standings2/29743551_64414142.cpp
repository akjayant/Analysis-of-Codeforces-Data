#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int dsu[maxn];
bool vis[maxn];
set<int>G[maxn];
set<int>st[maxn];
int ans;
int find(int x)
{
    return dsu[x]==x?x:dsu[x]=find(dsu[x]);
}
void comb(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y) ans--,dsu[y]=x;
}
int n,m;
void bfs(int x)
{
    int rt=find(x);
    if(rt==x)
    {
        for(int i=1;i<=n;i++)
            if(rt!=i)
                st[rt].insert(i);
    }
    queue<int>q;
    q.push(x);
    while(!q.empty())
    {
        int now=q.front();
        vis[now]=1;
        q.pop();
        vector<int>del;
        for(auto iter=st[rt].begin();iter!=st[rt].end();iter++)
        {
            int y=*iter;
            if(G[now].find(y)==G[now].end())
            {
                comb(now,y);
                del.push_back(y);
                if(!vis[y]) q.push(y);
            }
        }
        for(int i=0;i<del.size();i++)
            st[rt].erase(del[i]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) dsu[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].insert(v);
        G[v].insert(u);
    }
    ans=n;
    for(int i=1;i<=n;i++)
        if(!vis[i])
            bfs(i);
    cout<<ans-1<<endl;
}
