// IN THE NAME OF ALLAH.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back

const int N = 100 * 1000 + 1000,
			MOD = 1000 * 1000 * 1000 + 7;


int Pow(int a, int b){
	int ans = 1, c = a;
	while(b){
		if(b & 1)
			ans = (ans * c) % MOD;
		c = (c * c) % MOD;
		b >>= 1;
	}
	return ans;
}


int32_t main(){
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	cout << Pow(((Pow(2, m) + MOD - 1) % MOD), n) << '\n';

	return 0;
}