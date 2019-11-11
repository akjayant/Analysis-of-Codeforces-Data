#include <iostream>
#include <cstring>
using namespace std;

const int N = 100000 + 7;
const long long MOD = 1000000007;

int n;
char s[N];
long long f[N];
long long p;

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	
	for (int i = 1; i <= n; ++i)
		if (s[i] == 'm' || s[i] == 'w') return printf("0"), 0;
		
	f[1] = 1, f[2] = 2;
	for (int i = 3; i <= n; ++i)
		( f[i] = f[i - 2] + f[i - 1] ) %= MOD;
		
	p = 1;
	for (int i = 1, j; i <= n; i = j)
		if (s[i] != 'u' && s[i] != 'n')
			j = i + 1;
		else {
			for (j = i; j <= n && s[i] == s[j]; ++j);
			( p *= f[j - i] ) %= MOD;
		}
	printf("%I64d", p);

	return 0;
}
