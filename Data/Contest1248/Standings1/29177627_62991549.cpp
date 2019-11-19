#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;
const int maxn = 1e5 + 10;

LL n, m;
LL f[maxn][2];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	LL x = max(n, m);
	f[1][0] = 2;
	for(int i = 2; i <= x; i++)
	{
		f[i][1] = f[i - 1][0], f[i][0] = f[i - 1][0] + f[i - 1][1];
		f[i][1] %= mod, f[i][0] %= mod;
	}
	cout << (f[n][1] + f[n][0] + f[m][1] + f[m][0] - 2) % mod << endl;
	return 0;
}
