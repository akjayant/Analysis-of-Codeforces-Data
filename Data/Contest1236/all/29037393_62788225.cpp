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
int t, a, b, c;
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		int res = 0;
		for(int i = 0;i <= a;++i){
			if(b >= i * 2){
				for(int j = 0;j <= b;++j){
					if(b-i*2 >= j and j * 2 <= c){
						res = max(res, i + i * 2 + j + j * 2);
					}
				}
			}
		}
		cout << res << '\n';
	}
}