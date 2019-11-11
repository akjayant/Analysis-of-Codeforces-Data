#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 100005;
const int mod = 1000000007;

char c[maxn];

long long f[maxn];

int main (void)
{
	scanf("%s", c+1);
	int n = strlen(c+1);
	f[0] = 1;
	bool flag = 1;
	for(register int i=1; i<=n; ++i)
	{
		if(c[i] == 'u' && c[i-1] == 'u')
			f[i] = f[i-2] + f[i-1];
		else if(c[i] == 'n' && c[i-1] == 'n')
			f[i] = f[i-2] + f[i-1];
		else f[i] = f[i-1];
		f[i] %= mod;
		if(c[i] == 'w' || c[i] == 'm') flag = 0;
	}
	cout << (flag?f[n]:0);
	return 0;
}
