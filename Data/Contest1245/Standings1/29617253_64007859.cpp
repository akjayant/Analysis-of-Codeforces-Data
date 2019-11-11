#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int f[1000005];
char st[1000005];
int main() {
	scanf("%s", st + 1);
	int n = strlen(st + 1);
	f[1] = 1, f[2] = 2;
	for(int i = 3; i <= n; i ++) f[i] = f[i - 1] + f[i - 2], f[i] %= mod;
	long long ans = 1, s = 0;
	st[n + 1] = '$';
	for(int i = 1; i <= n + 1; i ++) {
		if(st[i] == 'w' || st[i] == 'm') {
			printf("0");
			return 0;
		}
		if(st[i] == st[i - 1] && (st[i] == 'u' || st[i] == 'n')) {
			s ++;
		} else {
			if(st[i - 1] == 'u' || st[i - 1] == 'n') ans = ans * f[s + 1] % mod, s = 0;
		}
	}
	printf("%I64d", ans);
	return 0;
}

