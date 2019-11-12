#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef _CONSOLE
	freopen("t.in", "r", stdin);
#endif

	int t, a, b, c, s;
	scanf("%d", &t);
	while (t--) {
		s = 0;
		scanf("%d%d%d", &a, &b, &c);
		s += min(b, c / 2) * 3;
		b -= min(b, c / 2);
		s += min(a, b / 2) * 3;
		printf("%d\n", s);
	}
}