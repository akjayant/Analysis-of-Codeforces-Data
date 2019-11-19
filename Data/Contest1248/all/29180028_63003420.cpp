#include <bits/stdc++.h>

using namespace std;

typedef double de;
typedef long long int LL;
const int N = 100100;

int n;
int to[N];
char s[N];
int ct, sta[N], vis[N];
int ctpo, po[N];

inline int get ( ) {
	int ans(0);
	for (int i = 1;i <= n; ++i)
		to[i] = 0, vis[i] = 0;
	ct = 0, ctpo = 0;
	for (int i = 1;i <= n; ++i)
		if (s[i] == '(')
			sta[++ct] = i;
		else {
			if (ct)
				to[i] = sta[ct --];
			else
				po[++ctpo] = i;
		}
	for (int i = 1;i <= ctpo; ++i)
		to[po[i]] = sta[ct --] - n;
	int fr(n);
	for (int i = 1;i <= n; ++i)
		if (s[i] == ')')
			fr = min( fr, to[i] );
	int now(0);
	for (int i = fr;i < fr + n; ++i) {
		int o(i < 1 ? i + n : i);
		if (s[o] == '(')
			now ++;
		else {
			now --;
			ans += (!now);
		}
	}
	return ans;
}

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int sum(0);
	scanf("%d", &n);
	scanf("%s", s + 1);

	for (int i = 1;i <= n; ++i)
		sum += (s[i] == '(');
	if (sum != n - sum) {
		printf("0\n");
		printf("1 1");
		return 0;
	}

	int ans(get( )), ansi(1), ansj(1);
	for (int i = 1;i < n; ++i)
		for (int j = i + 1;j <= n; ++j) {
			swap( s[i], s[j] );
			int tmp = get( );
			if (tmp > ans)
				ans = tmp, ansi = i, ansj = j;
			swap( s[i], s[j] );
		}

	printf("%d\n", ans);
	printf("%d %d", ansi, ansj);
	return 0;
}
