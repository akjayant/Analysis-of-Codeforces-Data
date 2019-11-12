#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 303;
const int mod = 1e9+7;

int mat[N][N];
int main() {
	int n;

	scanf("%d", &n);

	int i = 0, j = 0;

	int add = 1;
	for(int k = 1; k <= n * n; k++) {
		mat[i][j] = k;
		i += add;
		if(i == n or i == -1) {
			j++;
			add *= -1;
			i += add;
		}
	}

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%d%c", mat[i][j], " \n"[j + 1 == n]);
		}
	}
}
