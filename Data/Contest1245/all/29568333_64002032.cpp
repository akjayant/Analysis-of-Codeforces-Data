#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
using namespace std;
const int maxn = 1e2 + 10;
char s[maxn], ans[maxn];

int main()
{
	#ifdef DEBUG
	freopen("text.in", "r", stdin);
	#endif
	int t, n, a, b, c;
	scanf("%d", &t);
	while (t--) {
		int num = 0;
		scanf("%d%d%d%d", &n, &a, &b, &c);
		scanf("%s", s);
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'R' && b)
				ans[i] = 'P', --b, ++num;
			if (s[i] == 'P' && c)
				ans[i] = 'S', --c, ++num;
			if (s[i] == 'S' && a)
				ans[i] = 'R', --a, ++num;
		}
		if (num >= (n + 1) / 2) {
			puts("YES");
			for (int i = 0; i < n; ++i)
			if (ans[i] == '\0') {
				if (a) {
					ans[i] = 'R';
					--a;
				} else if (b) {
					ans[i] = 'P';
					--b;
				} else {
					ans[i] = 'S';
					--c;
				}
			}
			printf("%s\n", ans);
		} else puts("NO");
	}
	return 0;
}