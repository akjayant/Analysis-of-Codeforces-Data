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
 
void solve() 
{
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	string s;
    	cin >> n >> s;
    	int ans = n;
    	for (int i = 0; i < n; ++i) {
    		if (s[i] == '1') {
    			ans = max(ans, 2 * (i + 1));
    			ans = max(ans, 2 * (n - i));
    		}
    	}
    	cout << ans << endl;	
    }
}
 
int main( )
{   
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    solve();
    return 0;
}