#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#ifdef _debug
#define dout(i) cout << #i << ' ' << i << ' '
#else 
#define dout(i) //
#endif
using ll = long long;
using ull = unsigned long long;
using ul = unsigned;
using db = double;

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int ra = (a+c-1) / c, rb = (b+d-1) / d;
		if(ra + rb > k)cout << -1 << '\n';
		else cout << ra << ' ' << rb << '\n';
	}
}