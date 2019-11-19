#include <bits/stdc++.h>
#define int long long
#define ii pair<int , int >
using namespace std;
const int mn=1e6+5;
const int base=1e9+7;
int n,m,res=0,cnt[mn],d[mn];
set <int> sx[mn];
priority_queue <ii, vector <ii>, greater <ii> > q;
multiset <int> s;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin >> x >> y;
        sx[x].insert(y);
        sx[y].insert(x);
        cnt[x]++;
        cnt[y]++;
    }
    int minn = base, r = 0;
    for (int i=1;i<=n;i++)
        if (minn>cnt[i])
        {
            minn=cnt[i];
            r=i;
        }
    s.clear();
    for (int i=1;i<=n;i++)if (i!=r)s.insert(i);
    q.push({0,r});
    fill(d+1,d+n+1,base);
    d[r] = 0;
    while (!q.empty())
    {
        int u = q.top().second;
        int du = q.top().first;
        q.pop();
        if (du != d[u]) continue;
        res+=d[u];
        d[u]=0;
        vector<int> V;
        V.clear();
        for (int v : s)
        if (sx[u].find(v)==sx[u].end()&&d[v]>0)
        {
            d[v]=0;
            q.push({d[v],v});
            V.push_back(v);
        }
        for(int it : V)
        if(s.find(it)!=s.end())
        s.erase(s.find(it));
        for(int v:sx[u])
        if(d[v]>1)
        {
            d[v]=1;
            q.push({d[v],v});
        }
    }
    cout << res;
    return 0;
}
