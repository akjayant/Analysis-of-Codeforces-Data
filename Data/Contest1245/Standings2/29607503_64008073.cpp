#include <bits/stdc++.h>

#define N 100010

using namespace std;

char str[N];

bool vis[N];

int bu[4][4];

int main() {
	int T;
	cin >> T ;
	while (T -- ) {
		int n, ans;
		scanf("%d%d%d%d%s", &n, &bu[0][1], &bu[0][2], &bu[0][3], str + 1);
		bu[1][1] = bu[1][2] = bu[1][3] = ans = 0;
		memset(vis, false, sizeof vis);
		for (int i = 1; i <= n; i++) {
			if (str[i] == 'P' && bu[0][3]) {
				bu[0][3] -- ;
				vis[i] = true;
				ans ++ ;
			}
			if (str[i] == 'R' && bu[0][2]) {
				bu[0][2] -- ;
				vis[i] = true;
				ans ++ ;
			}
			if (str[i] == 'S' && bu[0][1]) {
				bu[0][1] -- ;
				vis[i] = true;
				ans ++ ;
			}
		}
		if (ans < (n + 1) / 2) {
			puts("No");
			continue;
		}
		puts("Yes");
		for (int i = 1; i <= n; i ++ ) {
			if (str[i] == 'P' && vis[i]) {
				putchar('S');
			}
			if (str[i] == 'P' && !vis[i]) {
				bu[0][1] ? putchar('R'), bu[0][1]-- : putchar('P'), bu[0][2]--;
			}
			if (str[i] == 'R' && vis[i]) {
				putchar('P');
			}
			if (str[i] == 'R' && !vis[i]) {
				bu[0][1] ? putchar('R'), bu[0][1]-- : putchar('S'), bu[0][3]--;
			}
			if (str[i] == 'S' && vis[i]) {
				putchar('R');
			}
			if (str[i] == 'S' && !vis[i]) {
				bu[0][3] ? putchar('S'), bu[0][3]-- : putchar('P'), bu[0][2]--;
			}
		}
		printf("\n");
	}
}