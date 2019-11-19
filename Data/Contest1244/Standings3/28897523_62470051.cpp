#include <bits/stdc++.h>
using namespace std;

int n;
char s[1005];

int main() {
	int t; scanf("%d", &t); while(t--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		int ans = -1;
		for(int i = 1; i <= n; i++) {
			if(s[i] == '1')
				ans = max(ans, max(i, n - i + 1));
		}
		ans = max(n, ans * 2);
		printf("%d\n", ans);
	}
	return 0;
}

