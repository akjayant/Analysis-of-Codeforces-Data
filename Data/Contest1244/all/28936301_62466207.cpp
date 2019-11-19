#include <bits/stdc++.h>
#define rep(i, n) for (rint i = 1; i <= (n); i ++)
#define re0(i, n) for (rint i = 0; i < (int) n; i ++)
#define travel(i, u) for (rint i = head[u]; i; i = e[i].nxt)
#define rint register int
using namespace std;

typedef long long lo;

template<typename tp> inline void read(tp &x) {
    x = 0; char c = getchar(); int f = 0;
    for (; c < '0' || c > '9'; f |= c == '-', c = getchar());
    for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
    if (f) x = -x;
}
const int N = 3e5 + 233;
int n;
char str[N];

int main(void) {
	int T;
	for (read(T); T--;) {
		read(n);
		scanf("%s", str + 1);
		rep (i, n) str[i] -= '0';
		int cnt = 0;
		rep (i, n) cnt += str[i];
		int ans = n;
		for (int i = 1; i <= n; i++)
			if (str[i] == 1) {
				ans = max(ans, 2 * i);
			}
		reverse(str + 1, str + n + 1);
		for (int i = 1; i <= n; i++)
			if (str[i] == 1) {
				ans = max(ans, 2 * i);
			}
		cout << ans << "\n";
	}
}

