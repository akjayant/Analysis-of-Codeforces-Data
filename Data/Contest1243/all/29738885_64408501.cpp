//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math") 
//#pragma GCC target("avx2")
#define _CRT_SECURE_NO_WARNINGS // - for VisualStudio: do not disturb about warnings
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <climits>

using namespace std;
#define open_streams ifstream fin("strange.in");ofstream fout("strange.out")
#define close_streams fin.close();fout.close()
#define speed cout.tie(0);cin.tie(0);ios_base::sync_with_stdio(0)
#define pus system("pause");
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define UNIQ(a) a.resize(unique(all(a)) - a.begin())
#define eps 1e-6
#define bpopcnt __builtin_popcountll // ll for long long
//const double PI = M_PI;
const int INF = INT_MAX;
const ll limit = 1LL * 1e18;
const int MOD = 1e9 + 711;
const int MOD2 = 1e9 + 933;
const int MOD3 = 1e9 + 993;
//---------------------------------------------------------------------------
const int mod = 1e9 + 7;
const int maxn = 5e5 + 100;




signed main() {
	speed;
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		map<char, int> S;
		for (int i = 0; i < n; ++i) {
			S[s[i]]++;
			S[t[i]]++;
		}
		bool ok = true;
		for (auto &i : S) {
			if (i.second % 2 != 0) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout << "No\n";
			continue;
		}
		//cout << "Yes\n";
		vector<pair<int, int>> a;
		vector<bool> good(n + 1);
		ok = true;
		for (int i = 0; i < n; ++i) {
			if (s[i] == t[i]) {
				good[i] = true;
			}
		}
		while (ok && s != t) {
			ok = false;
			bool was = false;
			for (int i = 0; i < n; ++i) {
				if (s[i] == t[i]) {
					good[i] = true;
					continue;
				}
				was = true;
				for (int j = 0; j < n; ++j) {
					if (!good[i] && !good[j] && i != j && s[i] == t[j] && s[j] == t[i]) {
						a.pb({ i + 1,i + 1 });
						swap(s[i], s[j]);
						a.pb({ i + 1,j + 1 });
						good[i] = good[j] = true;
						ok = true;
						break;
					}
					if (i != j && !good[i] && !good[j] && s[i] == s[j] && t[i] == t[j]) {
						a.pb({ i+1,j +1});
						swap(s[i], t[j]);
						good[i] = good[j] = true;
						ok = true;
						break;
					}
				}
				if (ok) {
					break;
				}
			}
			if (!ok && was) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						if (i != j && !good[i] && !good[j] && s[i] == s[j]) {
							swap(s[j], t[i]);
							a.pb({ j + 1,i + 1 });
							good[i] = true;
							ok = true;
							break;
						}
					}
				}
			}
			if (!ok && was) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						if (i != j && !good[i] && !good[j] && s[i] != t[j]) {
							a.pb({ i+1,j+1 });
							swap(s[i], t[j]);
							ok = true;
							break;
						}
					}
				}
			}
		}
		if (a.size() > 2 * n) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		cout << a.size() << '\n';
		//assert(a.size() <= 2 * n);
		for (auto &i : a) {
			cout << i.first << ' ' << i.second << '\n';
		}
	}
	cerr << "\n\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}