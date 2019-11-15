//#pragma GCC optimize ("-O3","unroll-loops")
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include <random>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define pb(a) push_back
#define print(x) cout<<x<<'\n'
#define pe(x) cout<<x<<" "
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define int long long
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
//#define double long double
//#define double float
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
//typedef pair<int, int>P;
const int MOD = 1e9 + 7; const int MAX = 200060;
const double pi = acos(-1); const double EPS = 1e-12;
const ll INF = 1e18;

long long gcd(long long x, long long y) {
	long long m = max(x, y), n = min(x, y);
	if (m%n == 0)return n;
	else return gcd(m%n, n);
}
int dp[100010][2];
void solve() {
	string S; cin >> S;
	dp[0][0] = 1;
	int N = S.size();
	REP(i, N) {
		if (i == 0) {
			
			dp[1][0] = 1;
			if (S[i] == 'm' || S[i] == 'w') {
				dp[i + 1][0] = 0, dp[i + 1][1] = 0;
			}
		}
		else{
			dp[i + 1][0] = dp[i][0] + dp[i][1];
			if (S[i] == 'm'||S[i]=='w') {
				dp[i + 1][0] = 0, dp[i + 1][1] = 0;
			}
			if (S[i] == 'u'&&S[i - 1] == 'u')dp[i+1][1] = dp[i][0];
			else if (S[i] == 'n'&&S[i - 1] == 'n')dp[i+1][1] = dp[i][0];
		}
		dp[i + 1][0] %= MOD;
		dp[i + 1][1] %= MOD;
	}
	ll ans = dp[N][0] + dp[N][1];
	ans %= MOD;
	print(ans);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	solve();
}