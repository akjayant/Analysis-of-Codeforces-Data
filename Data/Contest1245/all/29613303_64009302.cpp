#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5+100;
const int MOD = 1e9+7;

ll f[N];
char s[N];
int main() {
	f[0] = f[1] = 1;
	for(int i = 2; i < N; i++) {
		f[i] = f[i - 1] + f[i - 2];
		if(f[i] >= MOD) f[i] -= MOD;
	}

	scanf("%s", s);
	ll ans = 1;
	int n = strlen(s);
	for(int i = 0; i < n; i++) {
		if(s[i] == 'u' || s[i] == 'n') {
			int j = i;
			while(j + 1 < n && s[j + 1] == s[i])
				j++;
			ans = ans * f[j - i + 1] % MOD;
			i = j;
		}
		if(s[i] == 'm' || s[i] == 'w') ans = 0;
	}
	printf("%I64d\n", ans);
	return 0;
}