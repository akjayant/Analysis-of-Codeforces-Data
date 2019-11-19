#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e5+2;
const int MOD = 1e9+7;

int f[MAXN];

int n, m;

signed main(){
	cin >> n >> m;
	f[1] = 1; f[2] = 2;
	for(int i=3; i< MAXN; ++i) f[i] = (f[i-1]+f[i-2])%MOD;
	int ans = (2*f[n]+MOD-2)%MOD + (2*f[m])%MOD;
	cout << ans%MOD;
}
