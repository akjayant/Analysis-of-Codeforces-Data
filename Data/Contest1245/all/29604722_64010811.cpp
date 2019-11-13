#include "bits/stdc++.h"
#define N 100
using namespace std;
char s[N + 5], s1[N + 5];
int main(int argc, char const *argv[]) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, a, b, c;
		scanf("%d", &n);
		scanf("%d%d%d", &a, &b, &c);
		scanf("%s", s);
		int ans = n;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'R' && b)
				b--, s1[i] = 'P';
			else if (s[i] == 'P' && c)
				c--, s1[i] = 'S';
			else if (s[i] == 'S' && a)
				a--, s1[i] = 'R';
			else
				s1[i] = 0, ans--;
		}
		s1[n] = 0;
		for (int i = 0; i < n; i++)
			if (s1[i] == 0) {
				if (a) {
					s1[i] = 'R';
					a--;
					continue;
				}
				if (b) {
					s1[i] = 'P';
					b--;
					continue;
				}
				if (c) {
					s1[i] = 'S';
					c--;
					continue;
				}
			}
		if (ans >= (n + 1) / 2) printf("YES\n%s\n", s1); else puts("NO");
		// printf("%s\n", s1);
	}
	return 0;
}