#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, M, Fib[100010] = {}, MOD = 1000000007;
	Fib[0] = Fib[1] = 1;
	for (int i = 2; i <= 100000; i++) Fib[i] = (Fib[i - 1] + Fib[i - 2]) % MOD;
	cin >> N >> M;
	cout << (2 * (Fib[N] + Fib[M] - 1)) % MOD << endl;
}