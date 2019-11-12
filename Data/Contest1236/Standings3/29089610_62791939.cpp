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

const int N = 300 + 20 ;
int n , p1 , p2 ;
vector <int> vec[N] ;

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n ;

	int sz = 0 ;
	for (int i = 0 ; i < n ; i ++) {
		if (i & 1) {
			for (int j = 0 ; j < n ; j ++) {
				vec[j].pb(sz ++) ;	
			}
		}
		else {
			for (int j = n - 1 ; j >= 0 ; j --) {
				vec[j].pb(sz ++) ;
			}
		}
	}	

	for (int i = 0 ; i < n ; i ++) {
		for (int x : vec[i]) cout << x + 1 << ' ' ;
		cout << '\n' ;
	}
}
