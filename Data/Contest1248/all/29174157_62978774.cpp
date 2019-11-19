#include <bits/stdc++.h>

using namespace std ;

const long long int N = 2e5 + 100 ;
long long int n , m , q[N] , p[N] , t ;

int main(){
	cin >> t ;
	while(t--){
		long long int cnt1 = 0 , cnt2 = 0 , cnt3 = 0 ,cnt4 = 0 ;
		cin >> n ;
		for(int i = 0 ; i < n ; i++){
			cin >> p[i] ;
			if(p[i] % 2){
				cnt1++ ;
			}else{
				cnt2++ ;
			}
		}
		cin >> m ;
		for(int i = 0 ; i < m ; i ++){
			cin >> q[i] ;
			if(q[i] % 2){
				cnt3++ ;
			}else{
				cnt4++ ;
			}
		}
		cout << cnt1 * cnt3 + cnt2 * cnt4 << '\n' ;
	}
	return 0 ;
}
