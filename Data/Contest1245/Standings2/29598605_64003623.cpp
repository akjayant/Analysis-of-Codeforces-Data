#include <iostream>
using namespace std;

const int N = 100 + 7;

int t;
int n, a, b, c;
int x, y, z, k;
char s[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &a, &b, &c);
		scanf("%s", s + 1);
		x = a, y = b, z = c;
		k = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == 'R' && y)
				--y, ++k;
			if (s[i] == 'P' && z)
				--z, ++k;
			if (s[i] == 'S' && x)
				--x, ++k;
		}
		if (k >= (n + 1) / 2) printf("YES\n");
		else printf("NO\n");
		if (k >= (n + 1) / 2) {
			for (int i = 1; i <= n; ++i) {
				if (s[i] == 'R' && b) --b, printf("P");
				else if (s[i] == 'P' && c) --c, printf("S");
				else if (s[i] == 'S' && a) --a, printf("R");
				else if (x) --x, printf("R");
				else if (y) --y, printf("P");
				else --z, printf("S");
			}
			printf("\n");
		}
	}

	return 0;
}
