#include <bits/stdc++.h>

using namespace std;


#define int long long


int mod = 1e9 + 7;


void solve(){

	string s; cin >> s;

	int n = s.size();

	for(int i = 0; i < n; i++){
		if(s[i] == 'm' or s[i] == 'w'){
			cout << 0 << endl; return;
		}
	}

	vector < pair <int, int> > d(n);
	
	d[0].first = 1;
	d[0].second = 0;



	for(int i = 1; i < n; i++){
		if(s[i] == 'n' and s[i - 1] == 'n'){
			d[i].first = d[i - 1].first + d[i - 1].second;

			d[i].second = d[i - 1].first;
		}else

		if(s[i] == 'u' and s[i - 1] == 'u'){
			d[i].first = d[i - 1].first + d[i - 1].second;

			d[i].second = d[i - 1].first;
		}else{
			d[i].first = d[i - 1].first + d[i - 1].second;
		}

		d[i].first %= mod;
		d[i].second %= mod;
 	}


	cout << (d[n - 1].first + d[n - 1].second) % mod << endl;
 
}


main(){


	int test = 1;

	while(test--){
		solve();
	}



	return 0;
}


