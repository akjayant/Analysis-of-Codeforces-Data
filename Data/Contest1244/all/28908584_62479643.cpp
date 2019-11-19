#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define F first
#define S second
#define lp(i, a, b) for (int i=a;i<=(int)b;++i)
#define lp2(i, a, b) for (ll i=a;i>=b;--i)
#define f(x) return cout<<x<<"\n",0
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define p(x) cout<<#x<<" = { "<<x<<" } \n"
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define FAST ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define clr(c, x) memset(c,x,sizeof(c));
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int dx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
const int N = (int) 1e5 + 5, INF = 0x3f3f3f3f, ALPHA = 26;
const ll mod = 998244353;
vi lvl[4],v[N],p,vv;
vii ans;
ll sum[4][4]= {},c[N][4];
void dfs(int idx,int par,int l)
{
    lvl[l].pb(idx);
    for (auto u:v[idx])
    {
        if (u==par)
            continue;
        dfs(u,idx,(l+1)%3);
    }
}
int main()
{
#ifdef ONLINE_JUDGE
    FAST;
#endif
    int n;
    cin>>n;
    lp(j,0,2)
    {
        p.pb(j);
        lp(i,1,n)
        cin>>c[i][j];
    }
    lp(i,1,n-1)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    int start;
    lp(i,1,n)
    {
        if ((int)v[i].size()==1)
            start=i;
        if ((int)v[i].size()>2)
            f(-1);
    }
    dfs(start,start,0);
    lp(i,0,2)
    lp(j,0,2)
    for (auto u:lvl[i])
        sum[i][j]+=c[u][j];
    ll mn=(ll)1e17;
    do
    {
        ll summ=(sum[0][p[0]]+sum[1][p[1]]+sum[2][p[2]]);
        if (summ<mn)
        {
            mn=summ;
            vv=p;
        }
    }
    while(next_permutation(all(p)));
    cout<<mn<<"\n";
    lp(i,0,2)
    for (auto u:lvl[i])
        ans.pb({u,vv[i]});
    sort(all(ans));
    for (auto u:ans)
        cout<<u.S+1<<" ";
    return 0;
}