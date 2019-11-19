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

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define print(x) cout<<x<<'\n';
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ");
//#define double long double

template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
const int MAX = 200060;
const double pi = acos(-1);

int N, K; 
vector<int>A;
int calc(int l, int r) {
	int res = 0;
	REP(i, N) {
		if (A[i] < l) {
			res += l - A[i];
		}
		else if (A[i] > r) {
			res += A[i] - r;
		}
	}
	return res;
}
bool possible(int k) {
	int l = 0, r = 1e9;
	int cnt = 0;
	ll mn = 1e15;
	while (abs(r - l) > 3) {
		//pe(l)print(r);
		int l1 = l + (r - l) / 3;
		int l2 = l + (r - l) / 3 * 2;
		//pe(l1)print(l2);
		int tmp1 = calc(l1, l1 + k);
		int tmp2 = calc(l2, l2 + k);
		mn = min({ mn,tmp2,tmp1 });
		if (tmp1 < tmp2) {
			r = l2;
		}
		else l = l1;
		cnt++;
	}
	//pe(l)pe(l + k)print(calc(l, l + k));
	//pe(r)pe(r + k)print(calc(r, r + k));
	mn = min({ mn,calc(l, l + k), calc(r, r + k) });
	if (mn <= K)return true;
	else return false;
}
void solve() {
	cin >> N >> K;
	A.resize(N);
	REP(i, N) cin >> A[i];
	VSORT(A);
	int ok = 1e9, ng = -1;
	while (abs(ok - ng) > 1) {
		
		int mid = (ok + ng) / 2;
		//cout << "mid:" << mid << endl;
		if (possible(mid))ok = mid;
		else ng = mid;
	}
	print(ok);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
}