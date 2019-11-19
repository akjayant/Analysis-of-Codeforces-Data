#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1000000007;
int n,m,f[100010][2],ans;
signed main() {
	cin >> n >> m;
	f[1][0] = f[1][1] = 1;
	for (int i = 2;i <= max(n,m);i++) {
		f[i][0] = (f[i-1][1]+f[i-2][1])%mod;
		f[i][1] = (f[i-1][0]+f[i-2][0])%mod;
	} 
	cout << (f[m][0]+f[m][1]+f[m-1][0]+f[m-1][1]+f[n][0]+f[n][1]+f[n-1][0]+f[n-1][1]-2+mod)%mod;
    return 0;
}