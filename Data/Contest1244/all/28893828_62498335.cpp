#include <bits/stdc++.h>

#define task "D"
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (ll i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (ll i = (r); i >= (l); --i)
#define pb push_back
#define F first
#define S second
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // sort(arr, arr + N, by(a));

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;

typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;

// Limit
const ll N=1e5+4;
// Struct

// Variables
ll n,color[3]={0,1,2},c[3][N],dep[N],st;
ll ans=0,res=1e18+1,res1[N],ans1[N];
vi a[N];
// Function
void dfs(ll u,ll p)
{
    ans+=c[color[dep[u]%3]][u];
    ans1[u]=color[dep[u]%3]+1;
    for (ll v:a[u])
    {
        if (v==p) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
int main()
{
	//freopen(task".in","r",stdin);
	//freopen(task".out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	cin >> n;
	rep(i,0,2) rep(j,1,n) cin >> c[i][j];
	rep(i,1,n-1)
	{
	    ll u,v;
	    cin >> u >> v;
	    a[u].pb(v);
	    a[v].pb(u);
	}
	rep(i,1,n) if (a[i].size()>=3)
	{
	    cout << -1;
	    return 0;
	} else if (a[i].size()==1)
	{
	    st=i;
	}
	dfs(st,0);
	if (res>ans)
    {
        res=ans;
        rep(i,1,n) res1[i]=ans1[i];
    }
	ans=0;
    while (next_permutation(color,color+3))
    {
        //rep(i,0,2) cout << color[i] << " \n"[i==2];
        dfs(st,0);
        //cout << ans << '\n';
        if (res>ans)
        {
            res=ans;
            rep(i,1,n) res1[i]=ans1[i];
        }
        ans=0;
    }
    cout << res << '\n';
    rep(i,1,n) cout << res1[i] << ' ';
}
