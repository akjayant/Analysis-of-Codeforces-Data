#include<bits/stdc++.h>
#define int long long
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
int l, r, dig1[100], dig2[100], dp[105][2][2];
int getdp(int i, bool flag1, bool flag2) {
	if (!i) {
		return 1;
	}
	if (dp[i][flag1][flag2] != -1) return dp[i][flag1][flag2];
	int n1 = flag1 ? dig1[i] : 1, n2 = flag2 ? dig2[i] : 1, ans = 0;
	fw (j1, 0, n1 + 1) fw (j2, 0, n2 + 1) {
		if (j1 == 1 && j2 == 1) continue;
		ans += getdp(i - 1, flag1 && j1 == n1, flag2 && j2 == n2);
	}
	dp[i][flag1][flag2] = ans;
	return ans;
}
int solve(int r1, int r2) {
	if (r1 < 0 || r2 < 0) return 0;
	memset(dig1, 0, sizeof dig1);
	memset(dig2, 0, sizeof dig2);
	int ptr1 = 0, ptr2 = 0;
	while (r1) {
		dig1[++ptr1] = r1 & 1;
		r1 >>= 1;
	}
	while (r2) {
		dig2[++ptr2] = r2 & 1;
		r2 >>= 1;
	}
	memset(dp, -1, sizeof dp);
	return getdp(max(ptr1, ptr2), true, true);
}
void proc() {
	cin >> l >> r;
	cout << solve(r, r) - solve(l - 1, r) - solve(r, l - 1) + solve(l - 1, l - 1) << "\n";
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) proc();
	return 0;
}