#include<bits/stdc++.h>
const int N = 1e5 + 3;
const int MOD = 1e9 + 7;
#define int long long

int f[N][4],g[N][4],n,m;

inline int solveCol(int f[N][4],int n) /*f*/
{
	if(n == 1) return 2;
	f[2][0] = f[2][1] = f[2][2] = f[2][3] = 1;
	for(int i = 3;i <= n;i++) {
		f[i][0] = f[i - 1][2];
		f[i][3] = f[i - 1][1];
		f[i][1] = (f[i - 1][2] + f[i - 1][0]) % MOD;
		f[i][2] = (f[i - 1][3] + f[i - 1][1]) % MOD;
	}
	return ((f[n][0] + f[n][1]) % MOD + (f[n][2] + f[n][3]) % MOD) % MOD;
}

signed main()
{
	std::cin >> n >> m;
	auto  tmp0 = solveCol(f,n),tmp1 = solveCol(g,m);
	std::cout << (tmp0 + tmp1 - 2) % MOD;

	exit(0);
}
