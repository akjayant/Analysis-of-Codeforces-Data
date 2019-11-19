#include <bits/stdc++.h>
#define N 1005

using namespace std;

char s[N];

inline void cmax(int &u, int v) { if(u < v) u = v; }

int main() {
	int t, n;
	ios :: sync_with_stdio(0);
	cin >> t;
	while(t--) {
		cin >> n;
		cin >> (s + 1);
		int ans = n;
		for(int i = 1; i <= n; ++i) {
			if(s[i] == '1') {
				cmax(ans, 2 * (n - i + 1));
				break;
			}
		}
		for(int i = n; i >= 1; --i) {
			if(s[i] == '1') {
				cmax(ans, 2 * i);
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}