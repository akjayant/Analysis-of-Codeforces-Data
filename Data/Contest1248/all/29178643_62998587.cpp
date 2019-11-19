#include <iostream>

using namespace std;

typedef long long LL;

const int MAXN = 1e5 + 100;
const LL MOD = 1e9 + 7;

LL f[MAXN], fsum[MAXN];
int n, m;

int main()
{
	f[0] = 1;
	f[1] = 2;
	for (int i = 2; i < MAXN; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
	}
	fsum[1] = f[1];
	for (int i = 2; i < MAXN; i++) {
		fsum[i] = (f[i] + fsum[i - 1]) % MOD;
	}
	cin >> n >> m;
	LL ans = 1;
	if (n > 3) {
		ans += fsum[n -3];
		ans %= MOD;
	}
	if (n > 2) {
		ans++;
		ans %= MOD;
	}
	if (n > 1) {
		ans++;
		ans %= MOD;
	}
	if (m > 3) {
		ans += fsum[m -3];
		ans %= MOD;
	}
	if (m > 2) {
		ans++;
		ans %= MOD;
	}
	if (m > 1) {
		ans++;
		ans %= MOD;
	}
	cout << ans * 2 % MOD << endl;
	
	return 0;
}