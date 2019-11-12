#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#ifdef _debug
#define dout(i) cout << #i << ' ' << i << ' '
#else 
#define dout(i) 0 and 0
#endif
#define rout(i) (cout << i << '\n', 0)
using ll = long long;
using ull = unsigned long long;
using ul = unsigned;
using db = double;
const int p = 1000000007;
int n, m;	
ll res = 1;
ll binpow(int up, ll v = 2){
	ll res = 1;
	for(;up;up >>= 1, v = v * v % p)if(up & 1)res = res * v % p;
	return res;
}
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	cout << binpow(n, (binpow(m)+p-1)) << '\n';
}