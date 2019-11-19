#include <bits/stdc++.h>
#define sqr(a) ((a)*(a))
#define rsz resize
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
#define PI 3.1415926535897932384626
#define MAXN 100010

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll dp[MAXN][4][4],v[MAXN][3];
int ans[MAXN];
vector<int> g[MAXN];

struct state{
	int node,no1,no2;
}vnxt[MAXN][4][4];

ll solve(int node,int no1,int no2, int p)
{
	if(p!=-1 && g[node].size()==1)
	{
		forn(i,3)if(i!=no1 && i!=no2)
		{
			vnxt[node][no1][no2].node=-1;
			vnxt[node][no1][no2].no2=i;
			return v[node][i];
		}
	}
	if(dp[node][no1][no2]!=-1) return dp[node][no1][no2];
	ll ret=MAXN*1e9;
	forn(i,3)if(i!=no1 && i!=no2) forall(it,g[node])if(*it!=p)
	{
		ll aux=solve(*it,no2,i,node)+v[node][i];
		if(aux<ret)
		{
			ret=aux;
			vnxt[node][no1][no2].node=*it;
			vnxt[node][no1][no2].no1=no2;
			vnxt[node][no1][no2].no2=i;
		}
	}
	if(p==-1)
	{
		int auxnode=node,auxno1=no1,auxno2=no2,nn,nn1,nn2;
		while(auxnode!=-1)
		{
			ans[auxnode]=vnxt[auxnode][auxno1][auxno2].no2;
			nn=vnxt[auxnode][auxno1][auxno2].node;
			nn1=vnxt[auxnode][auxno1][auxno2].no1;
			nn2=vnxt[auxnode][auxno1][auxno2].no2;
			auxnode=nn;
			auxno1=nn1;
			auxno2=nn2;
		}
	}
	return dp[node][no1][no2]=ret;
}

int main()
{
	#ifdef REJUNTE
	freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,-1,sizeof(dp));
	int n;
	cin >> n;
	forn(j,3) forn(i,n) cin >> v[i][j];
	if(n==1)
	{
		ll ans=2e9+10;
		forn(i,3) ans=min(ans,v[0][i]);
		cout << ans << '\n';
		return 0;
	}
	if(n==2)
	{
		ll ans=2e9+10;
		forn(i,3)forn(j,3) if(i!=j) ans=min(ans,v[0][i]+v[1][j]);
		cout << ans << '\n';
		return 0;
	}
	forn(i,n-1)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	int root=-1;
	forn(i,n) 
	{
		if(g[i].size()>2)
		{
			cout << "-1\n";
			return 0;
		}
		else if(g[i].size()==1) root=i;
	}
	cout << solve(root,3,3,-1) << '\n';
	forn(i,n) cout << ans[i]+1 << ' ';
	return 0;
}