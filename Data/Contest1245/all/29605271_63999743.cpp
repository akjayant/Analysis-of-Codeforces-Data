#include <bits/stdc++.h>

#define sz(a) int(a.size())
using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, r, p, s;
		scanf("%d", &n);
		string M;
		cin >> r >> p >> s >> M;
		string ans;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (M[i] == 'R' && p) p--, ans += 'P', cnt++;
			if (M[i] == 'P' && s) s--, ans += 'S', cnt++;
			if (M[i] == 'S' && r) r--, ans += 'R', cnt++;

			if (sz(ans) == i) ans += ' ';
		}

		if (cnt*2 < n) {
			puts("NO");
			continue;
		}
		puts("YES");
		for (char &x : ans) {
			if (x == ' ') {
				if (p) p--, x = 'P';
				else if (s) s--, x = 'S';
				else r--, x = 'R';
			}
		}
		cout << ans << endl;
	}
}
