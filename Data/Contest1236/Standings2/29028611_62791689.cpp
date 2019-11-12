#include <cstdio>
using namespace std;

const int N = 307;
int n, a[N][N];

int main () {
    scanf ("%d", &n); int m = n * n;
    int f = 1, now = 1, k = 1;
	while (now <= m) {
		if (f) {
			for (int i = 1; i <= n; ++i) {
				a[i][k] = now;
				++now;
			}
		}
		else {
			for (int i = n; i; --i) {
				a[i][k] = now;
				++now;
			}
		}
		++k;
		f ^= 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < n; ++j) printf ("%d ", a[i][j]);
		printf ("%d\n", a[i][n]);
	}
	return 0;
}