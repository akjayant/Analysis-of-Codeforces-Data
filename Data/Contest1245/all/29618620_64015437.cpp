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
	int n; cin >> n;

	vector<int> x(n), y(n); rep(i, 0, n) {
		cin >> x[i] >> y[i];
	}
	vector<int> c(n); rep(i, 0, n) {
		cin >> c[i];
	}
	vector<int> k(n); rep(i, 0, n) {
		cin >> k[i];
	}


	using T = tuple<int, int, int>;
	priority_queue<T, vector<T>, greater<T>> pq;

	rep(i, 0, n) {
		pq.emplace(c[i], i, -1);
	}

	auto d = [&](int i, int j) {
		return abs(x[i] - x[j]) + abs(y[i] - y[j]);
	};

	int ans = 0;
	vector<int> ans1;
	vector<pair<int, int>> ans2;
	vector<bool> ok(n);
	int cnt = 0;
	while (pq.size()) {
		int cost, a, b; tie(cost, a, b) = pq.top(); pq.pop();
		dump(cost, a, b);
		if (cnt == n)break;
		if (b == -1) {
			if (ok[a])continue;
			ok[a] = true;
			ans1.push_back(a);
			rep(i, 0, n) {
				if (ok[i])continue;
				pq.emplace((k[i] + k[a]) * d(i, a), i, a);
			}
			ans += cost;
			cnt++;
		}
		else {
			if (ok[a] && ok[b])continue;
			if (!ok[a]) {
				ok[a] = true;
				rep(i, 0, n) {
					if (ok[i])continue;
					pq.emplace((k[i] + k[a]) * d(i, a), i, a);
				}
			}
			if (!ok[b]) {
				ok[b] = true;
				rep(i, 0, n) {
					if (ok[i])continue;
					pq.emplace((k[i] + k[b]) * d(i, b), i, b);
				}
			}
			ans2.emplace_back(a, b);
			ans += cost;
			cnt++;
		}
		dump(ans, ok);
	}

	cout << ans << endl;
	cout << ans1.size() << endl;
	cout << ans1[0] + 1; rep(i, 1, ans1.size()) { cout << " " << ans1[i] + 1; } cout << endl;
	cout << ans2.size() << endl;
	rep(i, 0, ans2.size()) { cout << ans2[i].first + 1 << " " << ans2[i].second + 1 << endl; }

	return 0;
}