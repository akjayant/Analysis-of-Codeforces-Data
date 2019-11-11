#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>

const int MAXN = 100100;
const int MOD = 1000000007;

int MyGCD(int a, int b) {
	if(b) return MyGCD(b, a % b);
	return a;
}

long long ModPow(long long x, long long y, long long z) {
	x %= z;
	long long ans = 1;
	while(y) {
		if(y & 1) ans = ans * x % z;
		x = x * x % z;
		y >>= 1;
	}
	return ans;
}

char s[MAXN];

int main() {
	int n, a, b, c, t;
	scanf("%s", s);
	long long cnt_u = 0, cnt_n = 0, ans = 1, pre = 0;
	for(int i = 0; s[i]; ++i) {
		if(s[i] == 'u') {
			++cnt_u;
		} else cnt_u = 0;
		if(s[i] == 'n') {
			++cnt_n;
		} else cnt_n = 0;
		if(s[i] == 'm' || s[i] == 'w') ans = pre = 0;
		long long tmp = pre;
		pre = ans;
		ans = (ans + (cnt_n + cnt_u >= 2 ? tmp : 0)) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}