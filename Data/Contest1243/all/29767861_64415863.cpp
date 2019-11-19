#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define inf 1e9+7

int main()
{
    int n,m,u,v;
    cin>>n>>m;
    bool vis[n+1]={};
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    set<int>te;
    for(int i=1;i<=n;i++)
        te.insert(i);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            //cout<<i<<endl;
            ans++;
            queue<int>q;
            q.push(i);
            vis[i]=1;
            te.erase(i);
            while(!q.empty())
            {
                u=q.front();
                q.pop();
                map<int,int>mp;
                for(int i=0;i<adj[u].size();i++)
                {
                    v=adj[u][i];
                    mp[v]=1;
                }
                vector<int>temp;
                for(auto x:te)
                {
                    if(!mp[x])
                    {
                        q.push(x);
                        vis[x]=1;
                        temp.push_back(x);
                    }
                }
                for(int i=0;i<temp.size();i++)
                    te.erase(temp[i]);
            }
        }
    }

    cout<<ans-1<<endl;
    return 0;
}
