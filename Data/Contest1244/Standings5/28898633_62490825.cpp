/*
 *Author - Abhas Jain
 */
 
#include <bits/stdc++.h>
 
#define F first
#define S second
#define all(c) c.begin(), c.end()
#define endl '\n'
#define pb push_back
#define mp make_pair 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
 
typedef long long ll;
typedef long double ld;
 
using namespace std;
using namespace __gnu_pbds;
template <typename A, typename B>
string to_string(pair<A, B> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef AJ47
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll> >,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
 
const ld PI = 3.141592653589793;
const ll INF = 9223372036854775807ll;
const ll mod = 1e9 + 7;
 
const int N = 1e5 + 2;

vector<int> adj[N];
vector<int> order;

void dfs (int node, int par) {
	for (int next : adj[node]) {
		if (next != par) {
			dfs (next, node);
		}
	}
	order.pb(node);
}

void solve() 
{
    int n;
    cin >> n;
    ll cost[n][3];
    for (int i = 0; i < n; ++i) {
    	cin >> cost[i][0];
    }
    for (int i = 0; i < n; ++i) {
    	cin >> cost[i][1];
    }
    for (int i = 0; i < n; ++i) {
    	cin >> cost[i][2];
    }
    vector<int> deg(n);
    for (int i = 0; i < n - 1; ++i) {
    	int a, b;
    	cin >> a >> b;
    	a--; b--;
    	deg[a]++;
    	deg[b]++;
    	adj[a].pb(b);
    	adj[b].pb(a);
    	if (deg[a] > 2 || deg[b] > 2) {
    		cout << -1 << endl;
    		return;
    	}
    }
    for (int i = 0; i < n; ++i) {
    	if (deg[i] == 1) {
    		dfs(i, -1);
    		break;
    	}
    }
    vector<pair<int, pair<int, int>>> color{{0, {1, 2}}, {0, {2, 1}}, {1, {0, 2}}, {1, {2, 0}}, {2, {1, 0}}, {2, {0, 1}}};
    int midx = -1;
    ll ans = INF;
    for (int i = 0; i < 6; ++i) {
    	ll cur = 0;
    	for (int j = 0; j < n; ++j) {
    		if (j % 3 == 0) {
    			cur += cost[order[j]][color[i].F];
    		} else if (j % 3 == 1) {
    			cur += cost[order[j]][color[i].S.F];
    		} else cur += cost[order[j]][color[i].S.S];
    	}
    	if (cur < ans) {
    		ans = cur;
    		midx = i;
    	}
    }
    vector<int> pr(n);
    for (int j = 0; j < n; ++j) {
    	if (j % 3 == 0) {
    		pr[order[j]] = color[midx].F;
    	} else if (j % 3 == 1) {
    		pr[order[j]] = color[midx].S.F;
    	} else pr[order[j]] = color[midx].S.S;
    }
    cout << ans << endl;
    for (int x : pr) cout << x + 1 << " ";
    cout << endl;
}
 
int main( )
{   
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    solve();
    return 0;
}