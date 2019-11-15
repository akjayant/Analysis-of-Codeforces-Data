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

const int N = 103;

int Q, n, a, b, c;
char s[N], t[N];

int main () {
	read (Q); while (Q--) {
		read (n);
		read (a), read (b), read (c);
		int i, tot = 0;
		scanf ("%s", s + 1);
		memset (t, 0, sizeof (t));
		for (i = 1; i <= n; ++i) {
			if (s[i] == 'P') {
				if (c) {
					t[i] = 'S';
					++tot;
					--c;
				}
				else t[i] = '\0';
			}
			else if (s[i] == 'S') {
				if (a) {
					t[i] = 'R';
					++tot;
					--a;
				}
				else t[i] = '\0';
			}
			else {
				if (b) {
					t[i] = 'P';
					++tot;
					--b;
				}
				else t[i] = '\0';
			}
		}
		if (tot >= n + 1 >> 1) {
			puts ("YES");
			for (i = 1; i <= n; ++i) {
				if (!t[i]) {
					if (a) {
						t[i] = 'R';
						--a;
					}
					else if (b) {
						t[i] = 'P';
						--b;
					}
					else {
						t[i] = 'S';
						--c;
					}
				}
			}
			t[n + 1] = '\0';
			printf ("%s\n", t + 1);
		}
		else puts ("NO");
	}
	return 0;
}

