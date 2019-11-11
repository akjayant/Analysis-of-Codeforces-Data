#include <bits/stdc++.h>

#define N 100010

using namespace std;

const int mod = 1000000007 ;

char s[N];

int f[N];
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i ++ ) {
		if (s[i] == 'm' || s[i] == 'w') {
			puts("0");
			return 0;
		}
	}
	for (int i = 1; i <= n; i ++ ) {
		if (s[i] == s[i - 1] && s[i] == 'u') {
			f[i] = (f[i - 1] + f[i - 2]) % mod;
		}
		else if (s[i] == s[i - 1] && s[i] == 'n') {
			f[i] = (f[i - 1] + f[i - 2]) % mod;
		}
		else {
			f[i] = f[i - 1];
		}
	}
	cout << f[n] << endl ;
	return 0;
}