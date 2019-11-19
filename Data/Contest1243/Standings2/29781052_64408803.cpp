#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair <int,int> pi;
const int mn=1e6+5;
const int oo=1e9+9;
int n,m,res,Count[mn],len[mn];
set <int> g[mn];
//987897897987987987
 main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
        Count[u]++;Count[v]++;
    }
    int minn=oo,r=0;
    for (int i=1;i<=n;i++)
        if (minn>Count[i])
        {
            minn=Count[i];
            r=i;
        }
    multiset <int> st;
    st.clear();
    for (int i=1;i<=n;i++)
        if (i!=r)
        st.insert(i);
    priority_queue <pi,vector<pi>,greater<pi> > qu;
    qu.push(pi(0, r));
    fill(len + 1, len + n + 1, oo);
    len[r] = 0;
    while (!qu.empty())
    {
        int u = qu.top().second, du = qu.top().first;
        qu.pop();
        if (du != len[u]) continue;
        res += len[u];
        len[u] = 0;
        vector <int> vt;
        vt.clear();
        for (auto v : st)
        if (g[u].find(v)==g[u].end() && len[v] > 0)
            {
                len[v] = 0;
                qu.push(pi(len[v], v));
                vt.push_back(v);
            }
        for (int it:vt)
        if (st.find(it)!= st.end())
        st.erase(st.find(it));
        for (auto v : g[u])
        if (len[v]>1)
            {
                len[v] = 1;
                qu.push(pi(len[v], v));
            }
    }
    cout<<res;
    return 0;
}
