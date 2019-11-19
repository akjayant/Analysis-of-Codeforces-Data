#include <bits/stdc++.h>
#define rep(i, a, b) for(int i(a), i##_ORZ(b); i <= i##_ORZ; i++)
#define drep(i, a, b) for(int i(a), i##_ORZ(b); i >= i##_ORZ; i--)
using namespace std;
const int maxn = 1010;
int n, f[maxn][3], ans;
char str[maxn];
void chkmax(int &a, int b) { a = max(a, b); }
void solve() {
	memset(f, 0, sizeof(f));
	rep(i, 1, n) {
		chkmax(f[i][0], f[i-1][0] + 1); 
		chkmax(f[i][1], f[i-1][1] + 1);
		chkmax(f[i][2], f[i-1][2] + 2);
		chkmax(f[i][2], f[i-1][0] + 2);
		chkmax(f[i][2], f[i-1][1] + 2);
		if(str[i] == '1') {
			chkmax(ans, f[i-1][2] + 2);
			chkmax(f[i][0], f[i-1][1] + 2);
			chkmax(f[i][1], f[i-1][0] + 2);
		}
		//cout << i << ' ' << f[i][0] << ' ' << f[i][1] << endl;
	}
	chkmax(ans, f[n][0]); chkmax(ans, f[n][1]);
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ans = 0;
		scanf("%d", &n);
		scanf("%s", str + 1);
		solve();
		reverse(str + 1, str + 1 + n);
		solve();
		printf("%d\n", ans);
	}
	return 0;
}
