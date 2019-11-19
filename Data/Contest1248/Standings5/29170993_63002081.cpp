#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
int n;
int m;
long long f[MAXN];
long long ans;
long long sum[MAXN];
int main()
{
	int i;
	cin >> n >> m;
	f[1] = 1;
	f[2] = 1;
	sum[1] = 1;
	sum[2] = 2;
	for(i = 3; i <= MAXN - 9; i++)
	{
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
//		cout << f[i] << " ";
		sum[i] = (sum[i - 1] + f[i]) % MOD;
	}
	ans = (ans + (sum[n - 1] << 1)) % MOD;
	ans = (ans + (sum[m - 1] << 1)) %MOD;
	ans = (ans + 2) % MOD;
	cout << ans % MOD << endl;
	return 0;
}
