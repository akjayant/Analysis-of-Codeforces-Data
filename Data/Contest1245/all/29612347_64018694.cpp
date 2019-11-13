#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

char ss[N];

bool vis[N];

int num[10][10], n, ans;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &n, &num[0][1], &num[0][2], &num[0][3]);
		scanf("%s", ss + 1);
		num[1][1] = 0;
		num[1][2] = 0;
		num[1][3] = 0;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			vis[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			if (ss[i] == 'P' && num[0][3]) {
				num[0][3]--;
				vis[i] = true;
				ans++;
			}
			if (ss[i] == 'R' && num[0][2]) {
				num[0][2]--;
				vis[i] = true;
				ans++;
			}
			if (ss[i] == 'S' && num[0][1]) {
				num[0][1]--;
				vis[i] = true;
				ans++;
			}
		}
		if (ans < (n + 1) / 2) {
			printf("No\n");
			continue ;
		}
		printf("Yes\n");
		for (int i = 1; i <= n; i++) {
			if (ss[i] == 'P' && vis[i]) {
				printf("S");
			}
			if (ss[i] == 'P' && !vis[i]) {
				if (num[0][1]) {
					printf("R");
					num[0][1] -- ;
				}
				else {
					printf("P");
					num[0][2] -- ;
				}
			}
			if (ss[i] == 'R' && vis[i]) {
				printf("P");
			}
			if (ss[i] == 'R' && !vis[i]) {
				if (num[0][1]) {
					printf("R");
					num[0][1] -- ;
				}
				else {
					printf("S");
					num[0][3] -- ;
				}
			}
			if (ss[i] == 'S' && vis[i]) {
				printf("R");
			}
			if (ss[i] == 'S' && !vis[i]) {
				if (num[0][3]) {
					printf("S");
					num[0][3] -- ;
				}
				else {
					printf("P");
					num[0][2] -- ;
				}
			}
		}
		puts("");
	}
	return 0;
}