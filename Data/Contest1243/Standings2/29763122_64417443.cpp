#include <bits/stdc++.h>
#define ll long long
#define int ll
#define iP pair<int,int>
using namespace std;
const int namduong=1e6+5;
const int uwu=1e9+7;
int n,m,res=0,counts[namduong],d[namduong];
set <int> ghks[namduong];
priority_queue <iP, vector <iP>, greater <iP> > q;
multiset <int> sosadUwU;
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        ghks[x].insert(y);
        ghks[y].insert(x);
        counts[x]++;
        counts[y]++;
    }
    int ghijk = uwu, r = 0;
    for (int i=1;i<=n;i++)
        if (ghijk>counts[i])
        {
            ghijk=counts[i];
            r=i;
        }
    sosadUwU.clear();
    for (int i=1;i<=n;i++)
        if (i!=r)sosadUwU.insert(i);
    q.push({0,r});
    fill(d+1,d+n+1,uwu);
    d[r] = 0;
    while (!q.empty())
    {
        int u=q.top().second;
        int du=q.top().first;
        q.pop();
        if (du != d[u]) continue;
        res+=d[u];
        d[u]=0;
        vector<int> nanidafuk;
        nanidafuk.clear();
        for (int v : sosadUwU)
        if(ghks[u].find(v)==ghks[u].end()&&d[v]>0)
        {
            d[v]=0;
            q.push({d[v],v});
            nanidafuk.push_back(v);
        }
        for(int it : nanidafuk)
        if(sosadUwU.find(it)!=sosadUwU.end())
        sosadUwU.erase(sosadUwU.find(it));
        for(int v:ghks[u])
        if(d[v]>1)
        {
            d[v]=1;
            q.push({d[v],v});
        }
    }
    cout<<res;
    return 0;
}
