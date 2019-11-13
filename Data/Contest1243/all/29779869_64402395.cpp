#include "bits/stdc++.h"

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define ll long long
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>istream &operator>>(istream &is, pair<T, S> &p) { is >> p.first >> p.second; return is; }
//template <typename T, typename S>ostream &operator<<(ostream &os, pair<T, S> &p) {os << p.first << " " << p.second;return os;}

template <typename T> void printvv(const vector<vector<T>> &v) {
	cerr << endl;
	rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
		if (typeid(v[i][j]).name() == typeid(INF).name() and v[i][j] == INF) {
			cerr << "INF";
		}
		else
			cerr << v[i][j];
		cerr << (j == v[i].size() - 1 ? '\n' : ' ');
	}
	cerr << endl;
}

#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
template <class T, class U>bool chmin(T& a, U b) { if (a > b) { a = b; return true; }return false; }
template <class T, class U>bool chmax(T& a, U b) { if (a < b) { a = b; return true; }return false; }

signed main(signed argc, char *argv[]) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	int T; cin >> T;
	loop(T) {
		int N; cin >> N;
		string s; cin >> s;
		string t; cin >> t;
		map<char, int>mp;
		for (auto c : s) {
			mp[c]++;
		}
		for (auto c : t) {
			mp[c]++;
		}
		bool f = true;
		for (auto p : mp) {
			if (p.second % 2 == 1) {
				f = false; break;
			}
		}
		if (not f) {
			Yes(0);
		}
		else {
			Yes(1);
			vector<pii>ans;
			rep(i, 0, N) {
				if (s[i] != t[i]) {
					rep(j, i + 1, N) {
						if (s[j] == s[i]) {
							ans.eb(j, i);
							swap(s[j], t[i]);
							break;
						}
					}
					if (s[i] != t[i]) {
						rep(j, i + 1, N) {
							if (t[j] == s[i]) {
								ans.eb(i + 1, j);
								swap(s[i + 1], t[j]);
								ans.eb(i + 1, i);
								swap(s[i + 1], t[i]);
								break;
							}
						}
					}
				}
			}
			assert(s == t);
			assert(ans.size() <= 2 * N);
			cout << ans.size() << endl;
			for (auto p : ans) {
				cout << p.first + 1 << " " << p.second + 1 << endl;
			}
		}
	}

	return 0;
}
