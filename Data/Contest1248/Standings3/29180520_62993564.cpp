#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m; 
int f[100005][5], mod = 1000000007, ans = 0;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	f[1][1] = 1;
	f[1][2] = 1; 
	for(int i = 2; i <= max(n, m); i++)
	{
		f[i][1] = (f[i-1][2] + f[i-1][4]) % mod;
		f[i][2] = (f[i-1][1] + f[i-1][3]) % mod;
		f[i][3] = f[i-1][1] % mod;
		f[i][4] = f[i-1][2] % mod;
	} 
	for(int i = 1; i <= 4; i++)
	{
		ans += f[m][i];
		ans %= mod;
		ans += f[n][i];
		ans %= mod;
	}
	ans -= 2;
	cout<<(ans + mod) % mod<<endl;
    return 0;
}