#include <bits/stdc++.h>

using namespace std;


#define int long long


int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

void solve(){

	int a, b; cin >> a >> b;

	if(gcd(a, b) == 1){
		cout << "Finite" << endl;
	}else{
		cout << "Infinite" << endl;
	}
	

}


main(){


	int test; cin >> test;

	while(test--){
		solve();
	}



	return 0;
}


