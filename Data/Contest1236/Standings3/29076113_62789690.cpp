#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, cnt;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &a, &b, &c);
		if(2*b >= c) {
			cnt = c/2*3;
			b -= c/2;
			if(2*a >= b) cnt += b/2*3;
			else cnt += a*3;
		} else cnt = b*3;
		printf("%d\n", cnt);
	}
	return 0;
}
