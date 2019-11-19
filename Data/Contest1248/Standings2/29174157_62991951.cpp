#include <bits/stdc++.h>

using namespace std ;

const long long int MD = 1e9 + 7 ;
long long int n , m , f[1000000] ;

int main(){
	cin >> n >> m ;
	f[1] = 2 ;
	f[2] = 4 ;
	for(int i = 3 ; i <= max(m , n) ; i++){
		f[i] = f[i - 1] + f[i - 2] ;
		f[i] %= MD; 
	}
	cout << (f[n] + f[m] - 2) % MD  ;
	return 0 ;
}
