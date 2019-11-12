#include "bits/stdc++.h"
#define N 300
using namespace std;
int a[N + 5][N + 5], n;
int main(int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int j = 1; j <= n; j += 2) {
		for (int i = 1; i <= n; i++)
			a[i][j] = i + (j - 1) * n;
		for (int i = n; i >= 1; i--)
			a[i][j + 1] = n - i + 1 + j * n;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}