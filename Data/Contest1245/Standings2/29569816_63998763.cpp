#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int T, n, a, b, c;
char s[105], t[105];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d%s", &n, &a, &b, &c, s + 1);
		int cnt = n; t[n + 1] = 0;
		for (int i = 1; i <= n; ++i) {
			if ('R' == s[i] && b) {
				t[i] = 'P';
				--b;
			}
			else if ('S' == s[i] && a) {
				t[i] = 'R';
				--a;
			}
			else if ('P' == s[i] && c) {
				t[i] = 'S';
				--c;
			}
			else {
				t[i] = 0;
				--cnt;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (0 == t[i]) {
				if (a) {
					t[i] = 'R';
					--a;
				} else if (b) {
					t[i] = 'P';
					--b;
				} else {
					t[i] = 'S';
					--c;
				}
			}
		}
		if (cnt >= (n + 1) / 2) {
			puts("YES");
			puts(t + 1);
		} else {
			puts("NO");
		}
	}
	return 0;
}
