#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline void read (int& s) {
	s = 0; int f = 0;
	static char c = getchar ();
	while (c < '0' || c > '9') {if (c == '-') f = 1; c = getchar ();}
	while (c >= '0' && c <= '9') s = (s << 3) + (s << 1) + (c ^ 48), c = getchar ();
	s = f ? -s : s; return ;
}

const int N = 100003, MOD = 1000000007;
char s[N];
int f[N], ans = 1;

inline int work (const int num) {
	return max (0, 2 * num - 3);
}

int main () {
	scanf ("%s", s + 1);
	int i, j, n = strlen (s + 1);
	f[1] = 1;
	f[2] = 2;
	f[3] = 3;
	for (i = 4; i <= n; ++i) {
		f[i] = f[i - 1] + f[i - 2];
		f[i] = f[i] >= MOD ? f[i] - MOD : f[i];
	}
	for (i = 1; i <= n; ++i) {
		if (s[i] == 'm' || s[i] == 'w') ans = 0;
		if (s[i] == 'u') {
			int t = 0;
			for (j = i; j <= n; ++j) {
				if (s[j] == 'u') ++t;
				else break;
			}
			i = j - 1;
			ans = 1ll * ans * f[t] % MOD;
		}
		else if (s[i] == 'n') {
			int t = 0;
			for (j = i; j <= n; ++j) {
				if (s[j] == 'n') ++t;
				else break;
			}
			i = j - 1;
			ans = 1ll * ans * f[t] % MOD;
		}
	}
	printf ("%d\n", ans);
	return 0;
}

