#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <cmath>
#include <functional>
#include <algorithm>
#include <utility>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <complex>
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long double C;
typedef complex<C> P;

#define X real()
#define Y imag()
#define Size(X) (int)X.size()
#define int long long
#define ui unsigned int
#define mp make_pair
#define timer fghge
#define y1 yjyjyju
#define all(X) (X).begin(), (X).end()
#define endl '\n'

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s, t; cin >> s >> t;
		vector<int> ctr(26);
		vector<pair<int, int>> order;
		for (int i = 0; i < n; i++)
			ctr[s[i] - 'a']++;
		for (int i = 0; i < n; i++)
			ctr[t[i] - 'a']++;
		for (auto &i : ctr) {
			if (i % 2 != 0) {
				cout << "NO" << endl;
				goto out;
			}
		}

		for (int q = 0; q < 10 * n; q++) {
			int cntr = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == t[i])
					continue;
				for (int j = 0; j < n; j++) {
					if (i == j) continue;
					if (s[j] == s[i] && t[i] == t[j] && s[j] != t[j]) {
						swap(s[j], t[i]);
						order.push_back({ j, i });
						cntr++;
						break;
					}
				}
			}

			for (int i = 0; i < n; i++) {
				if (t[i] == s[i])
					continue;
				for (int j = 0; j < n; j++) {
					if (i == j) continue;
					if (s[j] == s[i] && t[i] == t[j] && t[j] != s[j]) {
						swap(t[j], s[i]);
						order.push_back({ i, j });
						cntr++;
						break;
					}
				}
			}

			for (int i = 0; i < n; i++) {
				if (s[i] == t[i])
					continue;
				for (int j = 0; j < n; j++) {
					if (i == j) continue;
					if (s[j] == s[i] && s[j] != t[j]) {
						swap(s[j], t[i]);
						order.push_back({ j, i });
						goto ext;
					}
				}
			}

			for (int i = 0; i < n; i++) {
				if (t[i] == s[i])
					continue;
				for (int j = 0; j < n; j++) {
					if (i == j) continue;
					if (s[j] == s[i] && t[j] != s[j]) {
						swap(t[j], s[i]);
						order.push_back({ i, j });
						goto ext;
					}
				}
			}
			if (cntr > 0)
				continue;
			for (int i = 0; i < n; i++) {
				if (s[i] == t[i])
					continue;
				swap(t[i], s[i]);
				order.push_back({ i, i });
				break;
			}
		ext:;
		}
		if (order.size() <= 2 * n) {
			cout << "YES" << endl << order.size() << endl;
			for (auto &i : order)
				cout << i.first + 1 << " " << i.second + 1 << endl;
		}
		else
			cout << "NO" << endl;
	out:;
	}
	return 0;
}