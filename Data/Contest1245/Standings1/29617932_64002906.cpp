#include <cstdio>

#define R register
int T, N, M;
int gcd(R int a, R int b) {
	return b? gcd(b, a % b): a;
}

int main() {
	for(scanf("%d", &T); T--; ) {
		scanf("%d%d", &N, &M);
		puts(gcd(N, M) == 1? "Finite": "Infinite");
	}
	return 0;
}
