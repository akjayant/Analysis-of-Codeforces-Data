#include <bits/stdc++.h>

using namespace std;


void solve(){

	int n; cin >> n;


	string s; cin >> s;


	int record = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			record = max(record, max(i + 1, n - i) * 2);
		}
	}


	if(record == 0){
		cout << n << endl;
	}else{
		cout << record << endl;
	}

}


int main(){


	long long test; cin >> test;

	while(test--){
		solve();
	}



	return 0;
}


