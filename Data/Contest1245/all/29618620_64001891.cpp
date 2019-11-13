#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

template<typename T>
vector<T> gen_v(size_t a) { return vector<T>(a); }
template<typename T, typename ...Ts>
auto gen_v(size_t a, Ts... ts) { return vector<decltype(gen_v<T>(ts...))>(a, gen_v<T>(ts...)); }
template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }
template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v) { for (auto &e : t) fill_v(e, v); }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	string RPS = "RPS";
	rep(_, 0, t) {
		int n; cin >> n;
		int a, b, c; cin >> a >> b >> c;
		string s; cin >> s;
		int cnt[128] = {};
		cnt['R'] = a;
		cnt['P'] = b;
		cnt['S'] = c;
		int w[128] = {};
		w['R'] = 'P';
		w['P'] = 'S';
		w['S'] = 'R';
		string ans = "";
		int win = 0;
		for (auto c : s) {
			dump(c, w[c], cnt[w[c]]);
			if (cnt[w[c]] > 0) {
				cnt[w[c]]--;
				ans.push_back(w[c]);
				win++;
			}
			else {
				ans.push_back('*');
			}
		}
		dump(ans);
		rep(i, 0, n) {
			if (ans[i] == '*') {
				for (auto c : RPS) {
					if (cnt[c] > 0) {
						ans[i] = c;
						cnt[c]--;
						break;
					}
				}
			}
		}
		if (win >= (n / 2 + n % 2)) {
			cout << "YES" << endl;
			cout << ans << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}