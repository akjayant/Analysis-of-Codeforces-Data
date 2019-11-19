#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5 , mod = 1e9 + 7;

int n , m; 
int f[N] , g[N] , delta;

int main()
{
	cin >> n >> m;
	f[0] = f[1] = 2;
	for(int i = 2 ; i <= n ; i ++)
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	g[0] = g[1] = f[n] , delta = g[0] - 2;
	for(int i = 2 ; i <= m ; i ++)
		g[i] = ((g[i - 1] + g[i - 2] - delta) % mod + mod) % mod;
	cout << g[m] << endl;	
}
