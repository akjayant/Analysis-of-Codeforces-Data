#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define reset(a, v) memset((a), v, sizeof(a))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> matrix;

const int MOD = (int)1e9 + 7;

int n, m;
matrix base, identity;

matrix matMul(matrix A, matrix B) {
	matrix ret = matrix(2, vi());
	for (int i = 0; i < 2; i++) ret[i] = vi(2, 0);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j ++) {
			for (int k = 0; k < 2; k++) {
				ret[i][j] += (1ll * A[i][k] * B[k][j]) % MOD;
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}

matrix matExp(matrix base, int p) {
	matrix ret = identity;
	while (p) {
		if (p & 1) {
			ret = matMul(ret, base);
		}
		base = matMul(base, base);
		p >>= 1;
	}
	return ret;
}

int getNthFibonacci(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;

	matrix res = matExp(base, n-2);
	// for (int i = 0; i < 2; i++) {
	// 	for (int j = 0; j < 2; j++) {
	// 		printf("%d ", res[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return (1ll*res[1][0] + 1ll*2*res[1][1]) % MOD;
}

int main() {
	cin >> n >> m;
	base = matrix(2, vi());
	identity = matrix(2, vi());
	for (int i = 0; i < 2; i++) {
		base[i] = vi(2, 1);
		identity[i] = vi(2, 0);
	}
	base[0][0] = 0;
	identity[0][0] = identity[1][1] = 1;

	int fibN = getNthFibonacci(n);
	int fibM = getNthFibonacci(m);

	int diff = fibN-1;
	if (diff < 0) diff += MOD;

	int ans = (1ll*2*(fibM + diff)) % MOD;
	cout << ans << "\n";
	return 0;
}