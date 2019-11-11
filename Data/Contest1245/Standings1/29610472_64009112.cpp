#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 1e5 + 51, P = 1e9 + 7;

int n, ans = 1, x, y, f[N];
char s[N];
int main() {
	scanf("%s", s + 1), n = strlen(s + 1), f[0] = f[1] = 1;
	for (int i = 2; i <= n; i++) f[i] = (f[i - 1] + f[i - 2]) % P;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'm' || s[i] == 'w') return puts("0"), 0;
		if (s[i] != 'u' && x) ans = 1ll * ans * f[x] % P, x = 0;
		if (s[i] != 'n' && y) ans = 1ll * ans * f[y] % P, y = 0;
		x += s[i] == 'u', y += s[i] == 'n';
	}
	if (x) ans = 1ll * ans * f[x] % P, x = 0;
	if (y) ans = 1ll * ans * f[y] % P, y = 0;
	printf("%d", ans);
}