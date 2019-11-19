#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO
#define endl "\n"  // Since endl forces a buffer flush which slows down large I/O operations.
#define ff first
#define ss second
#define pb push_back
#define input(c, n) for (int i = 0; i < n; ++i) cin >> c[i];
#define exit_message(s) return 0 * printf(s)
#define show_all(c) for (auto i: c) cout << i << " "; cout << "\n";
#define display(c, a, n) cout << "Displaying array \"" << #c << "\" : \n"; for (int (i) = (a); (i) < (n); ++(i)) cout << (c)[(i)] << " "; cout << "\n";
#define forl(i, a, n) for (int i = (a); (i) < (n); ++(i))
#define dugbe(k) cerr << "-\t> " << #k << " = " << k << "\n";
#define dugbev(arr, idx) cerr << "-\t " << #arr << "[" << idx << "] : " << arr[idx] << "\n";

// What follows is a magical ordered set data structure.
// Supports the following functions:
// find_by_order(int k) - returns k'th smallest element (0-indexed)
// order_of_key(int k) - returns number of elements strictly smaller than k.
using namespace __gnu_pbds;
#define ordered_set tree <ll, null_type, greater_equal <ll>, rb_tree_tag, tree_order_statistics_node_update>
 
/* TIPS FOR DEBUGGING
 * Check if values are not overflowing (use long long where required)
 * Check if ranges are inclusive or not.
 * Check properly if greedy will work or not before using it.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Keep adding to this list.
*/
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
typedef pair<ll, ll> prll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pr> vpr;
ifstream in("input.txt");
const ll mod = 1e9 + 7;
const long double eps = 1e-7;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
long long true_rand(long long n)
{
	// Returns a random number between 0 and n - 1 inclusive using mt19937.
    uniform_int_distribution<long long> uid(0, n - 1);
    return uid(rng);
}
 
ll mod_pow(ll a, ll b, ll mod)
{
	if (b == 0)
		return 1LL;
 
	ll res = mod_pow(a, b >> 1, mod);
	res = (res * res) % mod;
	if (b & 1LL)
		res = (res * a) % mod;
	
	return res;
}
 
const int N = 1e6 + 5;
const ll INF = 1e18;

vi g[N], gt[N];
vi tout, vis(N);
vi scc;

void dfs1(int src)
{
	vis[src] = 1;
	for (auto e: g[src])
	{
		if (!vis[e])
			dfs1(e);
	}
	tout.pb(src);
}

void dfs2(int src)
{
	vis[src] = 1;
	scc.pb(src);
	for (auto e: gt[src])
	{
		if (!vis[e])
			dfs2(e);
	}
}

void dfs3(int src)
{
	vis[src] = 1;
	for (auto e: g[src])
	{
		if (!vis[e])
			dfs3(e);
	}
}

int32_t main()
{
	#ifdef FASTIO
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	#endif
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;

		forl(i, 0, n + 5)
		{
			g[i].clear();
			gt[i].clear();
		}

		tout.clear();
		scc.clear();

		forl(i, 0, m)
		{
			int a, b;
			cin >> a >> b;
			--a, --b;

			if (a == b)
				continue;
			
			g[b].pb(a);
			gt[a].pb(b);
		}

		// SCC
		forl(i, 0, n)
			vis[i] = 0;
		forl(i, 0, n)
		{
			if (!vis[i])
				dfs1(i);
		}
		forl(i, 0, n)
			vis[i] = 0;
		
		vector<vi> vec;
		for (int i = n - 1; i >= 0; --i)
		{
			int v = tout[i];
			if (!vis[v])
			{
				dfs2(v);
				vec.pb(scc);
				scc.clear();
				if ((int)vec.size() == 2)
					break;
			}
		}

		if ((int)vec.size() < 2)
		{
			cout << "No\n";
			continue;
		}

		// int ploop = (int)scc.size();

		int x = vec[0][0], y = vec[1][0];

		forl(i, 0, n)
		{
			vis[i] = 0;
		}

		dfs3(x);

		if (vis[y] == 1)
			scc = vec[0];
		else
			scc = vec[1];

		forl(i, 0, n)
		{
			vis[i] = 0;
		}
		for (auto e: scc)
			vis[e] = 1;

		if ((int)vec.size() < 2)
		{
			cout << "No\n";
		}
		else
		{
			cout << "Yes\n";
			int cnt = 0;
			forl(i, 0, n)
			{
				if (vis[i])
					++cnt;
			}
			cout << cnt << " " << n - cnt << "\n";
			forl(i, 0, n)
			{
				if (vis[i])
					cout << i + 1 << " ";
			}
			cout << "\n";
			forl(i, 0, n)
			{
				if (!vis[i])
					cout << i + 1 << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}