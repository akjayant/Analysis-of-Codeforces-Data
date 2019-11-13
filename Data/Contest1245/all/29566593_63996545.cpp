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
	int n, a, b;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &a, &b);
		puts(MyGCD(a, b) == 1 ? "Finite" : "Infinite");
	}
	return 0;
}