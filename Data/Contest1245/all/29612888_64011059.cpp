#include <bits/stdc++.h>
using namespace std;
 
int t, n, a, b, c;
char ch[105], ans[105];
 
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &a, &b, &c);
		scanf("%s", ch+1);
		for (int i = 1; i <= n; i++) ans[i] = 0;
		ans[n+1] = 0;
		for (int i = 1; i <= n; i++) {
			if (ch[i] == 'R' && b) b--, ans[i] = 'P';
			else if (ch[i] == 'P' && c) c--, ans[i] = 'S';
			else if (ch[i] == 'S' && a) a--, ans[i] = 'R';
		}
		if ((n-(a+b+c))*2 >= n) {
			puts("YES");
			for (int i = 1; i <= n; i++) 
				if (!ans[i]) {
					if (b) b--, ans[i] = 'P';
					else if (c) c--, ans[i] = 'S';
					else if (a) a--, ans[i] = 'R';
				}
			puts(ans+1);
		} else puts("NO");
	}
	return 0; 
}