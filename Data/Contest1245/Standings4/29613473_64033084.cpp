#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define ii pair<int,int>
#define mp make_pair
using namespace std;
int n;
ii pos[2005];
int c[2005];
int k[2005];
int p[2005];
int val[2005];
int root(int x)
{
    while(p[x] != x)
    {
        p[x] = p[p[x]];
        x = p[x];
    }
    return x;
}
void M(int i,int j)
{
    int x = root(i),y = root(j);
    if(x != y)
    {
      p[y] = x;
      val[x] = min(val[x],val[y]);
      val[y] = val[x];
    }
}
int get_dis(int i,int j)
{
    return abs(pos[i].fr-pos[j].fr)+abs(pos[i].sc-pos[j].sc);
}
int ok[2005];
vector < ii > R[2005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        p[i] = i;
        int x,y;
        cin>>x>>y;
        pos[i] = mp(x,y);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        val[i] = c[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
    }
    vector < ii > adj;
    vector < int > S;
    vector < pair < ll , ii > > g;
    ll res = 0;
    for(int i=1;i<=n;i++)
    {
        int minx = c[i];
        for(int j=1;j<=n;j++)
        {
            if(i == j)
                continue;
            int dis = get_dis(i,j);
            ll cost = 1LL * dis*(k[i]+k[j]);
            if(cost <= c[i])
            {
                g.push_back(mp(cost , mp(i,j)));
            }
        }
    }
    sort(g.begin(),g.end());
    for(int i=0;i<g.size();i++)
    {
        ll cc = g[i].fr;
        ii temp = g[i].sc;
        if(root(temp.fr)!= root(temp.sc))
        {
            ll C1 = val[root(temp.fr)];
            ll C2 = val[root(temp.sc)];
            ll d = abs(C1-C2);

            if(min(C1,C2)+cc <= C1+C2)
            {
                M(temp.fr,temp.sc);
                res+=cc;
                adj.push_back(temp);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        int par = root(i);
        R[par].push_back(mp(c[i],i));
    }
    for(int i=1;i<=n;i++)
    {
        sort(R[i].begin(),R[i].end());
    }
    for(int i=1;i<=n;i++)
    {
        if(R[i].size()>0)
        {
            ii temp = R[i][0];
            res+=temp.fr;
            S.push_back(temp.sc);
        }
    }
    cout<<res<<endl;
    cout<<S.size()<<endl;
    for(int i=0;i<S.size();i++)
    {
        cout<<S[i]<<" ";
    }
    cout<<endl;
    cout<<adj.size()<<endl;
    for(int i=0;i<adj.size();i++)
    {
        ii p = adj[i];
        cout<<p.fr<<" "<<p.sc<<endl;
    }
    return 0;
}
