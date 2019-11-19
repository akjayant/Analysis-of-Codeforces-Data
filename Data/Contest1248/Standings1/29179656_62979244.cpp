#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
LL read() {
	LL k = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
		k = k * 10 + c - 48, c = getchar();
	return k * f;
}
int main() {
	int t = read();
	while(t--) {
		LL odd1 = 0, odd2 = 0, even1 = 0, even2 = 0;
		int n = read();
		for(int i = 1; i <= n; ++i) {
			int x = read();
			if(x & 1) ++odd1;
			else ++even1;
		}
		int m = read();
		for(int i = 1; i <= m; ++i) {
			int x = read();
			if(x & 1) ++odd2;
			else ++even2;
		}
		LL ans = odd1 * odd2 + even1 * even2;
		printf("%lld\n", ans);
	}
	return 0;
}