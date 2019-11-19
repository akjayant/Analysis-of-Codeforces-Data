#include <bits/stdc++.h>

using namespace std;


void solve(){

	
	int a, b, c, d, k; cin >> a >> b >> c >> d >> k;


	if((a + c - 1) / c + (b + d - 1) / d <= k){
		cout << (a + c - 1) / c << " " << (b + d - 1) / d << endl;
	}else{
		cout << -1 << endl;
	}

}


int main(){


	int test; cin >> test;

	while(test--){
		solve();
	}



	return 0;
}


