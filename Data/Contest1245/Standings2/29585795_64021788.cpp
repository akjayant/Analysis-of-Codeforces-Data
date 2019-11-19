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
typedef pair<int, int>P;
const int MOD = 1e9 + 7; const int MAX = 200060;
const double pi = acos(-1); const double EPS = 1e-12;
const ll INF = 1e18;

long long gcd(long long x, long long y) {
	long long m = max(x, y), n = min(x, y);
	if (m%n == 0)return n;
	else return gcd(m%n, n);
}

bool used[2020];
int d[2020];
int pai[2020];
int X[2020], Y[2020];
int c[2020], k[2020];
void solve() {
	int N; cin >> N;
	//int M; cin >> M;
	REP(i, N) {
		d[i] = INF;
		used[i] = false;
	}
	REP(i, N) {
		cin >> X[i] >> Y[i];
	}
	REP(i, N)cin >> c[i];
	REP(i, N)cin >> k[i];
	int mn = 1e18, idx = 0;
	REP(i, N) {
		if (c[i] <= mn) {
			idx = i; mn = c[i];
		}
	}
	ll sum = mn;
	vector<int>mk;
	used[idx] = true; mk.push_back(idx);
	REP(i, N) {
		if (used[i])continue;
		int dist = (k[idx] + k[i])*(abs(X[idx] - X[i]) + abs(Y[idx] - Y[i]));
		if (dist < d[i]) {
			d[i] = dist;
			pai[i] = idx;
		}
	}
	vector<P>edges;
	REP(_, N - 1) {
		mn = 1e18;
		bool edge = true;
		int nxt_idx = 0;
		REP(i, N) {
			if (used[i])continue;
			int dist = (k[idx] + k[i])*(abs(X[idx] - X[i]) + abs(Y[idx] - Y[i]));
			if (dist < d[i]) {
				d[i] = dist; pai[i] = idx;
			}
			if (d[i] < mn) {
				nxt_idx = i;
				mn = d[i];
			}
		}
		REP(i, N) {
			if (used[i])continue;
			if (c[i] <= mn) {
				edge = false;
				nxt_idx = i; mn = c[i];
			}
		}
		idx = nxt_idx;
		if (edge) {
			edges.push_back({ idx,pai[idx] });
		}
		else {
			mk.push_back(idx);
		}
		used[idx] = true;
		sum += mn;
	}
	print(sum);
	print(mk.size());
	REP(i, mk.size()) {
		pe(mk[i] + 1);
	}cout << endl;
	print(edges.size());
	REP(i, edges.size()) {
		pe(edges[i].first+1); print(edges[i].second+1);
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	solve();
}