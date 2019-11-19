#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#define ll long long

const ll p = 1e9 + 7;

using namespace std;

struct matrix {
	ll a00, a01, a10, a11;
};

matrix fib(int n, matrix M) {
	if (n == 1) {
		return M;
	}
	if (n % 2 == 0) {
		matrix m = fib(n / 2, M);
		matrix t;
		t.a00 = (m.a00 * m.a00 + m.a01 * m.a10) % p;
		t.a01 = (m.a00 * m.a01 + m.a01 * m.a11) % p;
		t.a10 = (m.a10 * m.a00 + m.a11 * m.a10) % p;
		t.a11 = (m.a10 * m.a01 + m.a11 * m.a11) % p;
		return t;
	}
	matrix t;
	matrix m = fib(n - 1, M);
	t.a00 = (M.a00 * m.a00 + M.a01 * m.a10) % p;
	t.a01 = (M.a00 * m.a01 + M.a01 * m.a11) % p;
	t.a10 = (M.a10 * m.a00 + M.a11 * m.a10) % p;
	t.a11 = (M.a10 * m.a01 + M.a11 * m.a11) % p;
	return t;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n, m;
	cin >> n >> m;
	int N = max(m, n);
	matrix P;
	P.a00 = 0;
	P.a01 = 1;
	P.a10 = 1;
	P.a11 = 1;
	ll Fn = fib(n, P).a11;
	ll Fm = fib(m, P).a11;
	cout << (2 * Fn + 2 * Fm - 2) % p;
}