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

const int mod = 1e9 + 7 ;
int n , m ;

inline int pw (int a , int b) {
	int res = 1 ;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod ;
		a = 1ll * a * a % mod ;
		b >>= 1 ;
	}

	return res ;
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n >> m ;

	int a = (pw(2 , m) + mod - 1) % mod ;

	cout << pw(a , n) << '\n' ;
}
