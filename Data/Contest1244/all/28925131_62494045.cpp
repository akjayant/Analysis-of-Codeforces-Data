//mridul1809
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define p(x) printf("%d ",x)
#define pl(x) printf("%lld ",x)
#define pd(x) printf("%lf ",x)
#define ps(x) printf(x)
#define pend printf("\n")
#define nm 100005
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
vector <int> tree[nm];
ll cost[nm][3];
int deg[nm];
vector <int> conf;
int ans[nm];
int dfs(int u,int p)
{
	conf.pb(u);
	for(int i=0;i<tree[u].size();i++)
	{
		if(tree[u][i] == p)
			continue;
		dfs(tree[u][i] , u);
	}
	return 0;
}
ll eval(int a,int b,int c)
{

	// debug(a,b,c);
	int i;
	ll ans = 0;
	for(int i=0;i<conf.size();i+=3)
	{
		ans = ans + cost[conf[i]][a-1];
		// debug(i , conf[i] , cost[conf[i]][a-1]);
		if(i+1 < conf.size())
		{
			ans = ans + cost[conf[i+1]][b-1];
			// debug(i+1 , conf[i+1] , cost[conf[i+1]][b-1]);
		}

		if(i+2 < conf.size())
		{
			ans = ans + cost[conf[i+2]][c-1];
			// debug(i+2 , conf[i+2] , cost[conf[i+2]][c-1]);
		}
	}
	// debug(ans);
	return ans;
}
ll display(int a,int b,int c)
{
	int i;
	for(int i=0;i<conf.size();i+=3)
	{
		ans[conf[i]] = a;

		if(i+1 < conf.size())
			ans[conf[i+1]] = b;

		if(i+2 < conf.size())
			ans[conf[i+2]] = c;
	}
	for(i=1;i<=conf.size();i++)
		cout << ans[i] << " ";
	cout << endl;
}
int main()
{
	int n,i,u,v,x=0;

	s(n);
	for(i=1;i<=n;i++)
		cin >> cost[i][0];

	for(i=1;i<=n;i++)
		cin >> cost[i][1];

	for(i=1;i<=n;i++)
		cin >> cost[i][2];

	for(i=1;i<n;i++)
	{
		cin >> u >> v;
		tree[u].pb(v);
		tree[v].pb(u);
		deg[u]++;
		deg[v]++;
		if(deg[u] > 2)
			x++;

		if(deg[v] > 2)
			x++;
	}

	if(x)
	{
		cout << -1 << endl;
		return 0;
	}

	for(i=1;i<=n;i++)
		if(deg[i] == 1)
			break;

	dfs(i , -1);

	// debug(conf);

	ll ans = (ll)mod * (ll)mod;

	ans = min(ans , eval(1,2,3));
	ans = min(ans , eval(1,3,2));
	ans = min(ans , eval(2,1,3));
	ans = min(ans , eval(2,3,1));
	ans = min(ans , eval(3,1,2));
	ans = min(ans , eval(3,2,1));

	cout << ans << endl;


	if(ans == eval(1,2,3))
		display(1,2,3);

	else if(ans == eval(1,3,2))
		display(1,3,2);

	else if(ans == eval(2,1,3))
		display(2,1,3);

	else if(ans == eval(2,3,1))
		display(2,3,1);

	else if(ans == eval(3,1,2))
		display(3,1,2);
	else
		display(3,2,1);
}