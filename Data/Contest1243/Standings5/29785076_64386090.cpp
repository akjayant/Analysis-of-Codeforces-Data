#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
char s[maxn], t[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int k, n, p1, p2, cnt;
	cin >> k;
	while (k--) {
		cin >> n >> s >> t;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				if (cnt == 0) p1 = i;
				if (cnt == 1) p2 = i;
				cnt++;
			}
		}
		if (cnt == 0) cout << "YES" << endl;
		else if (cnt == 2) {
			if (s[p1] == s[p2] && t[p1] == t[p2]) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}