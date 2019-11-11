#include <algorithm>
#include <cstdio>
#include <cstring>
#define R a--, t[i] = 'R'
#define P b--, t[i] = 'P'
#define S c--, t[i] = 'S'

char s[111], t[111];
int n, a, b, c, l;

int main() {
	for (scanf("%*d"); ~scanf("%d%d%d%d%s", &n, &a, &b, &c, s + 1); l = 0) {
		for (int i = 1; i <= n; i++) {
			if (s[i] == 'R' && b) P, l++;
			if (s[i] == 'P' && c) S, l++;
			if (s[i] == 'S' && a) R, l++;
		}
		for (int i = 1; i <= n; i++) {
			if (t[i])
				;
			else if (a)
				R;
			else if (b)
				P;
			else if (c)
				S;
		}
		if (l >= (n + 1) / 2)
			printf("YES\n%s\n", t + 1);
		else
			puts("NO");
		memset(t, 0, sizeof t);
	}
}