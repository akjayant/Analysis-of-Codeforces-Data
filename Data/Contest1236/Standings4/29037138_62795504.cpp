#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
int n;
int a[maxn][maxn], v[maxn];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) v[i] = i + 1;
/*	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			printf("%d ", j * n + v[(i + j) % n]);
			a[i][j] = j * n + v[(i + j) % n];
		}
		puts("");
	} */
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			if(i & 1) a[j][i] = j + 1 + i * n;
			else a[j][i] = i * n + n - j;
		}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}