#include <bits/stdc++.h>

using namespace std;

#define int long long
#define loop(i,n) for(int i = 0; i<n; ++i)
#define all(a) a.begin(),a.end()
#define FOR(i,n,m) for(int i = n; i<m; ++i)
#define rall(a) a.rbegin(),a.rend()

const int MOD = 1e9+7;

int binpow (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return (binpow(a, n-1) * a)%MOD;
	else {
		int b = binpow (a, n/2)%MOD;
		return (b * b)%MOD;
	}
}

signed main()
{
    int n,m;
    cin >> n >> m;
    cout << binpow((binpow(2,m)-1),n) << endl;
}
