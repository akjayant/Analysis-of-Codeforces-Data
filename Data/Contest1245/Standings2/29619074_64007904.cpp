#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

char out[101];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, a, b, c;
		scanf("%d %d %d %d", &n, &a, &b, &c);
		char seq[101];
		scanf("%s", seq);

		for (int i = 0; i < n; i++) {
			out[i] = 0;
		}

		int wc = 0;
		for (int j = 0; j < n; j++) {
			bool win = false;
			for (int i = 0; i < n; i++) {
				if (out[i] != 0) continue;
				if (seq[i] == 'R' && b > 0) {
					b--;
					out[i] = 'P';
					win = true;
					break;
				}
				else if (seq[i] == 'P' && c > 0) {
					c--;
					out[i] = 'S';
					win = true;
					break;
				}
				else if (seq[i] == 'S' && a > 0) {
					a--;
					out[i] = 'R';
					win = true;
					break;
				}
			}

			if (win) {
				wc++;
			}
			else {
				for (int i = 0; i < n; i++) {
					if (out[i] == 0) {
						if (a > 0) {
							out[i] = 'R';
							a--;
							break;
						}
						else if (b > 0) {
							out[i] = 'P';
							b--;
							break;
						}
						else {
							out[i] = 'S';
							c--;
							break;
						}
					}
				}
			}
		}

		if ((int)ceil(n / 2.0) <= wc) {
			printf("YES\n");
			for (int i = 0; i < n; i++) {
				printf("%c", out[i]);
			}
			printf("\n");
		}
		else {
			printf("NO\n");
		}
	}
}