#include <bits/stdc++.h>

using namespace std;


#define int long long


void solve(){


	int n, a, b, c;

	cin >> n >> a >> b >> c;

	string s; cin >> s;


	vector <char> ans(n, '#');

	int cnt = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == 'R'){
			if(b){
				ans[i] = 'P';
				b--;
				cnt++;
			}
		}

		if(s[i] == 'P'){
			if(c){
				ans[i] = 'S';
				c--;
				cnt++;
			}
		}

		if(s[i] == 'S'){
			if(a){
				ans[i] = 'R';
				a--;
				cnt++;
			}
		}
	}


	for(int i = 0; i < n; i++){
		if(ans[i] == '#' and a){
			a--;
			ans[i] = 'R';
		}

		if(ans[i] == '#' and b){
			b--;
			ans[i] = 'P';
		}

		if(ans[i] == '#' and c){
			c--;
			ans[i] = 'S';
		}
	}


	if(cnt >= (n + 1) / 2){
		cout << "YES" << endl;
		for(char c : ans){
			cout << c;
		}
		cout << endl;
	}else{
		cout << "NO" << endl;
	}

	

}


main(){


	int test; cin >> test;

	while(test--){
		solve();
	}



	return 0;
}


