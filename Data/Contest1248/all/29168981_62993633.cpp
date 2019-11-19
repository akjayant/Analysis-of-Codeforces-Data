#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define llu unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pf push_front
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fill(x,v) fill(all(x), v)
#define sumv(v) accumulate(all(v), 0LL)
#define bitcount(x) __builtin_popcount(x)
#define present(v,x) ((v).find(x) != (v).end())
#define cpresent(v,x) (find(all(v),x) != (v).end())
#define v2(type, v, n, m) vector<vector<type>> v(n, vector<type>(m))
#define v3(type, v, x, y, z) vector<vector<vector<type>>> v(x, vector<vector<type>>(y, vector<type>(z)))
#define unique(v) {sort(all(v)); v.resize(unique(all(v))-v.begin());}

const int MOD = 1000000007;
// const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-6;

#define cerr cout
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
string to_string(_Bit_reference b) { return (b ? "true" : "false");}
void debug_out() { cerr << ""; }
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(v, n) {for(int j=0; j<n; j++){debug_out(v[j]); if(j<n-1) cerr<<",";}}
#define dbg(...) {cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); { cerr << endl; }}
#define dbg1d(v, n) {cerr << "[" << #v << "]: {"; pr(v, n); {cerr << " }" << endl;}}
#define dbg2d(v, n, m) {cerr<<"["<<#v<<"]:"<<endl;{for(int i=0; i<n; i++){cerr<<right<<setw(10)<<"["+to_string(i)+"] {";pr(v[i],m);{cerr<<" }"<<endl;}}}}
#define shout()  {cerr << "I'm Here...!!!" << endl;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
random_device rd; mt19937 mt(rd()); uniform_int_distribution<long long> mtrng(1,LONG_LONG_MAX);
inline long long myRand() {return mtrng(mt);}

inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = (n%p) * (n%p) % p;} return r;}
inline int inv(ll a, int p = MOD) {return fpow(a, p - 2, p);}
inline int addmod(int a, int val, int p = MOD) {{if ((a = (a + val)) >= p) a -= p;} return a;}
inline int submod(int a, int val, int p = MOD) {{if ((a = (a - val)) < 0) a += p;}return a;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	v2(ll, dp, max(n, m)+1, 2);
	dp[1][1] = 1;
	for(int i=2; i<=max(n, m); i++){
		dp[i][1] = addmod(dp[i-1][1], dp[i-1][0]);
		dp[i][0] = dp[i-1][1];
	}

	ll res = mult(2, addmod(addmod(dp[n][0], dp[n][1]), addmod(dp[m][0], dp[m][1]-1)));
	cout << res << endl;

	return 0;
}