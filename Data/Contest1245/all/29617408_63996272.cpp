#include<bits/stdc++.h> 

using namespace std ; 



int32_t main() { 
	int tc ; 
	cin >> tc ; 
	while(tc--) { 
		int a , b ; 
		cin >> a >> b  ;
		int g = __gcd(a , b) ; 
		if(g == 1) 
			cout << "Finite" << endl ; 
		else
			cout << "Infinite" << endl ; 
	}	
}
