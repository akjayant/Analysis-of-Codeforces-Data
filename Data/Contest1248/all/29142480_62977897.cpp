#include <bits/stdc++.h>
#define rep(i, a, b) for(int i(a), i##_ORZ(b); i <= i##_ORZ; i++)
#define drep(i, a, b) for(int i(a), i##_ORZ(b); i >= i##_ORZ; i--)
using namespace std;
const int maxn = 100010;
int n, m;
long long p[2], q[2];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int t; p[0] = p[1] = q[0] = q[1] = 0;
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &t), p[t % 2]++;
		scanf("%d", &m);
		rep(i, 1, m) scanf("%d", &t), q[t % 2]++;
		printf("%lld\n", p[0] * q[0] + p[1] * q[1]);
	}
	return 0;
}
