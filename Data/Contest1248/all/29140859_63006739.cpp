#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;

void solve() {
	int n, ans = 0, ansl = 1, ansr = 1;
	string s;
	cin >> n >> s;
	
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += (s[i] == '(' ? 1 : -1);
	if (sum != 0) {
		cout << 0 << endl;
		cout << 1 << " " << 1;
		return;
	}
	
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j) {
			string t = s;
			swap(t[i], t[j]);
			
			int cnt = 0, mn = 0, pos = 0;
			for (int k = 0; k < n; ++k) {
				cnt += (t[k] == '(' ? 1 : -1);
				if (cnt < 0 && t[k] == ')' && cnt < mn) {
					mn = cnt;
					pos = k + 1;
				}
			}
			if (pos == -1) {
				cnt = 0;
				mn = 0;
				for (int k = n - 1; k >= 0; --k) {
					cnt += (t[k] == ')' ? 1 : -1);
					if (cnt < 0 && t[k] == '(' && cnt < mn) {
						mn = cnt;
						pos = k;
					}
				}
			}
			
			string a = t.substr(pos, n - pos);
			string b = t.substr(0, pos);
			string c = a + b;
			
			int res = 0;
			cnt = 0;
			for (int k = 0; k < n; ++k) {
				cnt += (c[k] == '(' ? 1 : -1);
				res += (cnt == 0);
			}
			
			if (res > ans) {
				ans = res;
				ansl = i + 1;
				ansr = j + 1;
			}
		}
	
	cout << ans << endl;
	cout << ansl << " " << ansr;
}

int main() {
	solve();
	/*
	int n, ans = 0, ansl = 1, ansr = 1;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j) {
			string t = s;
			swap(t[i], t[j]);
			int res = n;
			for (int k = 0; k < n; ++k) {
				string a = t.substr(k, n - k);
				string b = t.substr(0, k);
				string ss = a + b;
				int cnt = 0;
				for (int pos = 0; pos < n; ++pos) {
					cnt += (ss[pos] == '(' ? 1 : -1);
					if (cnt < 0) {
						--res;
						break;
					}
				}
			}
			if (res > ans) {
				ans = res;
				ansl = i + 1;
				ansr = j + 1;
			}
		}
	
	cout << ans << endl;
	cout << ansl << " " << ansr;
	*/
	return 0;
}