#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
#define N 300005
//#define f first
//#define s second
//#define int long long
using namespace std;

const int MOD=1e9+7;
int n, m;
int res = 0, d[N];
vector < int > ke[N], st, vt;
void BFS(int u1)
{
    queue < int > qu;
    qu.push(u1);
    d[u1] = 1;
    while(qu.size())
    {
        int u = qu.front();
        qu.pop();
        for(int i = 0; i < vt.size(); i ++)
        {
            int x = vt[i];
            if(d[x] == 1)
                continue;
            int ck1 = lower_bound(ke[u].begin(), ke[u].end(), x) - ke[u].begin();
            int ck2 = upper_bound(ke[u].begin(), ke[u].end(), x) - ke[u].begin();
            if(ck1 == ck2)
            {
                d[x] = 1;
                st.push_back(x);
                qu.push(x);
            }
        }
        for(int x : st)
        {
            int xx = lower_bound(vt.begin(), vt.end(), x) - vt.begin();
            vt.erase(xx + vt.begin());
        }
        st.clear();
    }
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
//    freopen("1243D.inp","r",stdin);
//    freopen("1243D.out","w",stdout);
    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    FOR(i, 1, n) sort(ke[i].begin(), ke[i].end());
    FOR(i, 2, n) vt.push_back(i);
    FOR(i, 1, n)
    {
        if(d[i] == 0)
        {
            res ++;
            BFS(i);
        }
    }
    cout << res - 1;
}
