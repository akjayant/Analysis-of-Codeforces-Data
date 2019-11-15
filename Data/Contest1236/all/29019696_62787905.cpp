#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int power(int a, int b){
	int ans = 1;
	while(b){
		if(b&1)
			ans = (ans*a) % mod;
		b >>= 1;
		a = (a*a) % mod;
	}
	return ans;
}
 
signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n, m;
	cin >> n >> m;
	int x = (power(2, m) - 1 + mod) % mod;
	x = power(x, n);
	cout << x << endl;
	return 0;
}