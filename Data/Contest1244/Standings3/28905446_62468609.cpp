#include <bits/stdc++.h>
#define rep(i, a, b) for(int i(a), i##_ORZ(b); i <= i##_ORZ; i++)
#define drep(i, a, b) for(int i(a), i##_ORZ(b); i >= i##_ORZ; i--)
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int a, b, c, d, k;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int x = a / c, y = b / d;
		if(x * c < a) x++; if(y * d < b) y++;
		if(x + y > k) printf("-1\n");
		else printf("%d %d\n", x, y);
	}
	return 0;
}
