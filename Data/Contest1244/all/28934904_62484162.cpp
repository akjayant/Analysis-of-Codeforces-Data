// You either die a hero, or you live long enough to see yourself become the villain.

/**
 *   author:  Blind_is_love
 *   created: 13.10.2019, 15:11
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <class Arg1> void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
    template <class Arg1, class... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* sep = strchr(names + 1, ',');
        cerr.write(names, sep - names) << " : " << arg1 << "  ";
        __f(sep + 1, args...);
    }
#else
#define trace(...) 0
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#endif // ifndef ONLINE_JUDGE

#define endl "\n"
#define vll vector<int>
#define max_heap priority_queue<int>
#define min_heap priority_queue<int , vector<int>, greater<int> >
#define pb push_back
#define all(container) container.begin(), container.end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define printArr(name,from,to) for(int x = from; x < to; x++) {cout << name[x] << " ";} cout << endl;
#define fi first
#define se second
#define mp make_pair
#define prime1 304933
#define prime2 15486277 
#define mod2 179424691
#define int ll

typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; 

const ll MOD = 1000000007;
const ll MAX = 1e5+10;
const double PI = 3.1415926;
const ll INF = 1e18;
const double EPS = 1e-5;
int n;
int color[3][MAX];
vll adj[MAX];
int color_node[MAX];

void dfs(int s, int p, int cur, int par){
	color_node[s] = cur;
	int color_child = 3 - cur - par;
	for(int x : adj[s]){
		if (x == p) continue;
		dfs(x, s, color_child, cur);
	}
	return ;
}

int solve(){
	int ans = 0;
	for(int i =0 ; i < n; ++i){
		ans += color[color_node[i]][i];
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	clock_t t1, t2;
	t1 = clock();
	cin >> n;
	for(int i = 0 ; i < 3; ++i){
		for(int j = 0; j < n; ++j){
			cin >> color[i][j];
		}
	}
	for(int i =0 ; i < n-1; ++i){
		int x,y;
		cin >> x >> y;
		x--;y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(int i = 0; i < n; ++i){
		if (adj[i].size() > 2){
			cout << -1 << endl;
			return 0; 
		}
	}
	int ans = 1e18;
	pii opt;
	for(int i = 0 ; i < 3; ++i){
		for(int j = 0 ; j < 3;++j){
			if (i == j) continue;
			memset(color_node,-1,sizeof(color_node));
			color_node[0] = i;
			dfs(adj[0][0], 0, j, i);
			if (adj[0].size() == 2){
				dfs(adj[0][1], 0, (3 - i - j), i);
			}
			int c = solve();
			if (c < ans){
				ans = c;
				opt = mp(i,j);
			}
		}
	}

	memset(color_node,-1,sizeof(color_node));
	color_node[0] = opt.fi;
	dfs(adj[0][0], 0, opt.se, opt.fi);
	if (adj[0].size() == 2){
		dfs(adj[0][1], 0, (3 - opt.fi - opt.se), opt.fi);
	}
	cout << ans << endl;
	for(int i =0 ; i < n; ++i){
		cout << color_node[i]+1 << " ";
	}
	cout << endl;
	t2 = clock(); cerr << "time taken: " << (t2-t1)/(long double)CLOCKS_PER_SEC << endl;
	return 0;
}
