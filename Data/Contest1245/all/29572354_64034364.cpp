#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 1;

map<char,int> mp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	mp['R'] = 1;
	mp['P'] = 2;
	mp['S'] = 0;
	string foo = "RPS";
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[3];
		for (int i = 0; i < 3; i++) {
			cin >> a[i];
		}
		string s;
		cin >> s;
		string ans = "";
		for (int i = 0; i < n; i++) {
			ans.push_back('?');
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int x = mp[s[i]];
			if (a[x] > 0) {
				ans[i] = foo[x];
				a[x]--;
				cnt++;
			}
		}
		if (cnt < (n + 1) / 2) {
			cout << "NO" << endl;
			continue;
		}
		string bar = "";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < a[i]; j++) {
				bar.push_back(foo[i]);
			}
		}
		for (int i = 0, j = 0; i < n; i++) {
			if (ans[i] == '?') {
				ans[i] = bar[j];
				j++;
			}
		}
		cout << "YES" << endl;
		cout << ans << endl;
	}
	return 0;
}