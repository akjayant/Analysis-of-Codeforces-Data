#include <bits/stdc++.h>
using namespace std;

int a, b, c, ans;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &a, &b, &c), ans = 0;
		int t = min(b, c / 2);
		b -= t,  ans = t * 3;
		ans += min(a, b / 2) * 3;
		printf("%d\n", ans);
	}
	return 0;
}

