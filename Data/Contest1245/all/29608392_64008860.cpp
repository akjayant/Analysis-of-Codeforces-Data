#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
char s[210000];
ll f[210000];

int main() {
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i <= 110000; i++)
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
	scanf(" %s", s);
	int flag = 1;
	ll ans = 1;
	int lens = strlen(s);
	int sumu = 0, sumn = 0;
	for (int i = 0; i < lens; i++) {
		if (s[i] == 'u') {
			sumu++;
		} else {
			ans = ans * f[sumu] % MOD;
			sumu = 0;
		}
		if (s[i] == 'n') {
			sumn++;
		} else {
			ans = ans * f[sumn] % MOD;
			sumn = 0;
		}
		if (s[i] == 'm' || s[i] == 'w') flag = 0;
	}
	ans = ans * f[sumn] % MOD * f[sumu] % MOD;
	if (flag == 0) {
		puts("0");
	} else printf("%lld\n", ans);
	return 0;
}