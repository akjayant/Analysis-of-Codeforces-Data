#include <bits/stdc++.h>
using namespace std;
char s[1010];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, ct = 0, res; scanf("%d%s", &n, s + 1), res = n;
		for (int i = 1; i <= n; i++) 
			if (s[i] == '1') ct++;
		res = max(res, ct + n);
		for (int i = 1; i <= n; i++) 
			if (s[i] == '1') res = max(res, max(i, n - i + 1) * 2);
		printf("%d\n", res);
	}
}