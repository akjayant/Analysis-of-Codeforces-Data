/**
 * author:  apikdech
 * created: 01.11.2019 21:43:27
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;

char ans[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, cnt = 0;
		cin >> n;
		int r, p, sc;
		cin >> r >> p >> sc;
		string s;
		cin >> s;
		for (int i = 0; i < n; i++) ans[i] = ' ';
		for (int i = 0; i < n; i++) {
			if (s[i] == 'R' && p) ans[i] = 'P', p--, cnt++;
			else if (s[i] == 'P' && sc) ans[i] = 'S', sc--, cnt++;
			else if (s[i] == 'S' && r) ans[i] = 'R', r--, cnt++;
		}
		for (int i = 0; i < n; i++) {
			if (ans[i] != ' ') continue;
			if (s[i] == 'P' && p) ans[i] = 'P', p--;
			else if (s[i] == 'R' && r) ans[i] = 'R', r--;
			else if (s[i] == 'S' && sc) ans[i] = 'S', sc--;
		}
		for (int i = 0; i < n; i++) {
			if (ans[i] != ' ') continue;
			if (p) ans[i] = 'P', p--;
			else if (r) ans[i] = 'R', r--;
			else if (sc) ans[i] = 'S', sc--;
		}
		// cout << cnt << "\n";
		if (cnt >= (n+1)/2) {
			cout << "YES\n";
			for (int i = 0; i < n; i++) cout << ans[i];
			cout << "\n";
		}
		else cout << "NO\n";
	}
	return 0;
}
