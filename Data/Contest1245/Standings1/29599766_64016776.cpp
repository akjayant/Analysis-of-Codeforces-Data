#include <bits/stdc++.h>

using namespace std;

bool mark[10001];
char str[10001];
int n;
char ch[4] = {'R', 'P', 'S'};
int t, a[101];
char s[1001];
int main( ) {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 0; i < 3; i ++) scanf("%d", &a[i]);
		scanf("%s", str + 1);
		int ans = 0;
		
		for (int i = 1; i <= n; i ++) {
			int type = 0;
			if (str[i] == 'P') type = 1;
			else if (str[i] == 'S') type = 2;
			if (a[(type + 1) % 3]) {
				-- a[(type + 1) % 3];
				++ ans;
				s[i] = ch[(type + 1) % 3];
				mark[i] = true;
			}
			else mark[i] = false;
		}
		for (int i = 1; i <= n; i ++) {
			if (mark[i] == true) continue;
			if (a[0]) {
				-- a[0];
				s[i] = ch[0];
			} else if (a[1]) {
				-- a[1];
				s[i] = ch[1];
			}
			else if (a[2]) {
				-- a[2];
				s[i] = ch[2];
			}
		}
		s[n + 1] = '\0';
		if (ans >= (n + 1) / 2) {
			printf("YES\n");
			puts(s + 1);
		}
		else printf("NO\n");
	}
	return 0;
}
