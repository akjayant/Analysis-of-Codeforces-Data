#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define II pair < int , int > 
#define pb push_back
#define Hmax priority_queue < int > 
#define Hmin priority_queue < int , vector < int > , greater < int > >
#define IImax priority_queue < II >  
#define IImin priority_queue < II , vector < II > , greater < II > >
#define FOR(i , a , b) for(int i = a ; i <= b ; ++i)
#define FOD(i , a , b) for(int i = a ; i >= b ; --i)
const int inf = 1e15;
const int N = 2e3 + 5;
int n , k[N] , par[N];
vector < II > Out;
vector < int > xx;
vector < pair < int , II > > Ed;
II a[N];
void Input()
{
	if(fopen("trash.inp" , "r"))
		freopen("trash.inp" , "r" , stdin) , freopen("trash.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> a[i].fi >> a[i].se;
	}
	for(int i = 1 ; i <= n ; ++i)
	{
		int x;
		cin >> x;
		Ed.pb({x , {0 , i}});
	}
	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> k[i];
	}
	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = i + 1 ; j <= n ; ++j)
		{
			int cost = (abs(a[i].fi - a[j].fi) + abs(a[i].se - a[j].se)) * (k[i] + k[j]);
			Ed.pb({cost , {i , j}});
		}
	}
}
int Root(int u)
{
	if(par[u] < 0) return u;
	par[u] = Root(par[u]);
	return par[u];
}
bool Merge(int u , int v)
{
	if((u = Root(u)) == (v = Root(v))) return false;
	if(par[u] > par[v]) swap(u , v);
	par[u] += par[v];
	par[v] = u;
	return true;
}
void Solve()
{
	sort(Ed.begin() , Ed.end());
	memset(par , -1 , sizeof par);
	int Res = 0;
	for(int i = 0 ; i < Ed.size() ; ++i)
	{
		int w = Ed[i].fi , u = Ed[i].se.fi , v = Ed[i].se.se;
		if(Merge(u , v))
		{
			Res = Res + w;
			if(u == 0 || v == 0) 
			{
				if(u == 0) xx.pb(v);
				else xx.pb(u);
			}
			else Out.pb({u , v});
		}
	}
	cout << Res << '\n' << xx.size() << '\n';
	for(int i = 0 ; i < xx.size() ; ++i) cout << xx[i] << ' ';
		cout << '\n';
	cout << Out.size() << '\n';
	for(int i = 0 ; i < Out.size() ; ++i) cout << Out[i].fi << ' ' << Out[i].se << '\n';
}
#undef int
int main()
{
	Input();
	Solve();
}