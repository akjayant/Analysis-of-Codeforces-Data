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

char s[MAXN], ans[MAXN];

int main() {
	int n, a, b, c, t;
	scanf("%d", &t);
	while(t--) {
		memset(ans, 0, sizeof(ans));
		scanf("%d%d%d%d", &n, &a, &b, &c);
		scanf("%s", s);
		int win = 0;
		for(int i = 0; i < n; ++i) {
			if(s[i] == 'R') {
				if(b) {
					--b;
					ans[i] = 'P';
					++win;
				}
			} else if(s[i] == 'P') {
				if(c) {
					--c;
					ans[i] = 'S';
					++win;
				}
			} else {
				if(a) {
					--a;
					ans[i] = 'R';
					++win;
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			if(ans[i]) continue;
			if(s[i] == 'R') {
				if(a) {
					--a;
					ans[i] = 'R';
				} else {
					--c;
					ans[i] = 'S';
				}
			} else if(s[i] == 'P') {
				if(b) {
					--b;
					ans[i] = 'P';
				} else {
					--a;
					ans[i] = 'R';
				}
			} else {
				if(c) {
					--c;
					ans[i] = 'S';
				} else {
					--b;
					ans[i] = 'P';
				}
			}
		}
		if(win >= (n + 1) / 2) {
			puts("YES");
			puts(ans);
		} else puts("NO");
	}
	return 0;
}