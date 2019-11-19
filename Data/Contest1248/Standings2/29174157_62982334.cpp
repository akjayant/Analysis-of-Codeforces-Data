#include <bits/stdc++.h>

using namespace std ;

const long long int N = 2e5 + 100 ;
long long int n , a[N] , ans , cnt;

int main(){
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	sort(a , a + n); 
	for(int i = 0 ; i < n / 2 ; i++){
		ans += a[i] ;
	}
	ans *= ans ;
	for(int i = n / 2 ; i < n ; i++){
		cnt  += a[i] ;
	}
	cout << cnt * cnt + ans ;
	return 0 ;
}
