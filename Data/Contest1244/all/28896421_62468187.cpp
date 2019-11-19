#include <bits/stdc++.h>
using namespace std;

int n;
string s;

signed main(){
	int T; cin >> T;
	while(T--){
		cin >> n >> s;
		int ans = n;
		for(int i=0; i< n; ++i){
			if(s[i] == '1') ans = max(ans, 2*max(i+1, n-i));
		}
		cout << ans << "\n";
	}
}
