#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1000000;
int a, b, dp[N];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &a, &b);
		if(__gcd(a, b) == 1) printf("Finite\n");
		else puts("Infinite");
	}
	return 0;
}