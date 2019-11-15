#include "bits/stdc++.h"
using namespace std;
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main(int argc, char const *argv[]) {
	int T, a, b;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &a, &b);
		puts(gcd(a, b) == 1 ? "Finite" : "Infinite");
	}
	return 0;
}