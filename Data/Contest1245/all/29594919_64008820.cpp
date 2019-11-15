#include<bits/stdc++.h>

using namespace std;
#define endl '\n'

typedef pair<int, int> pii;
typedef long long ll;

const int N = 1e6, MOD = 1e9 + 7;;
char s[N];

int up(int x){
	return (x + 1) / 2;
}

void solve(){
	int a , b , c, n;
	cin >> n;
	cin >> a >> b >> c;
	string foo;
	cin >> foo;
	
	vector<bool> flag(n);
	vector<char> ans(n);

	int wins = 0;
	while(a > 0){
		bool done = false;
		for(int j =0; j < n; j++){
			if(!flag[j] && foo[j] == 'S') {
				flag[j] = true;
				ans[j] = 'R';
				a--;
				wins++;
				done = true;
				break;
			}
		}
		if(!done){
			break;
		}
	}

	while(b > 0){
		bool done = false;
		for(int j =0; j < n; j++){
			if(!flag[j] && foo[j] == 'R') {
				flag[j] = true;
				ans[j] = 'P';
				b--;
				wins++;
				done = true;
				break;
			}
		}
		if(!done){
			break;
		}
	}
	while(c > 0){
		bool done = false;
		for(int j =0; j < n; j++){
			if(!flag[j] && foo[j] == 'P') {
				flag[j] = true;
				ans[j] = 'S';
				c--;
				wins++;
				done = true;
				break;
			}
		}
		if(!done){
			break;
		}
	}


	for(int i = 0; i < n; i++){
		if(!flag[i]){
			if(a > 0){
				ans[i] = 'R';
				a--;
			}else if (b > 0){
				ans[i] = 'P';
				b--;
			}
			else if(c > 0){
				ans[i] = 'S';	
				c--;
			}
		}
	}

	
	if(wins >= up(n)){
		cout << "YES" << endl;
		string sol = "";
		for(auto v : ans){
			sol += v;
		}
		cout << sol << endl;
	}
	else{
		cout << "NO" << endl;
	}

}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	int t;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}

