#include <bits/stdc++.h>

#define F(i, a, b) for (int i = a; i <= b; i ++)
#define G(i, a, b) for (int i = a; i >= b; i --)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define mx(a, b) ((a) = max(a, b))
#define mn(a, b) ((a) = min(a, b))
#define mem(a, b) memset(a, b, sizeof a)
#define mec(a, b) memcpy(a, b, sizeof a)
#define pf printf
#define sf scanf

using namespace std;

const int N = 1e4 + 10;
int k, len;
char s[N], t[N];

int main() {
	for (sf("%d", &k); k --; ) {
		sf("%d%s%s", &len, s + 1, t + 1);
		int cnt = 0;
		F(i, 1, len)
			cnt += (s[i] != t[i]);
		if (!cnt)
			puts("Yes");
		else
		if (cnt == 2) {
			int x1 = 0, x2 = 0;
			F(i, 1, len)
				if (s[i] != t[i]) { x1 = i; break; }
			G(i, len, 1)
				if (s[i] != t[i]) { x2 = i; break; }
			if (t[x2] == t[x1] && s[x1] == s[x2])
				puts("Yes");
			else
				puts("No");
		}
		else
			puts("No");
	}
}