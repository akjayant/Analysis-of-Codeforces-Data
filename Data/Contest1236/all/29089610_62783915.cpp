//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()
#define pb push_back

#define error(x) cout << #x << " = " << x << endl

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

int q , a , b , c ;

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> q ;

	while (q --) {
		cin >> a >> b >> c ;

		int ans = 0 ;
		for (int i = 0 ; i <= a ; i ++) {
			if (2 * i > b) continue ;

			ans = max(ans , 3 * i + 3 * min(b - 2 * i , c / 2)) ;
		}

		cout << ans << '\n' ;
	}

}
