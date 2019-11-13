#include <stdio.h>
const int N = 1e3+10;
int a[N][N];
int main() {
	int n; scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		if (i&1) {
			for (int j=1; j<=n; j++) {
				a[j][i] = (i-1)*n+j;
			}
		} else {
			for (int j=n, k=1; j>0; j--, k++) {
				a[j][i] = (i-1)*n+k;
			}
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}