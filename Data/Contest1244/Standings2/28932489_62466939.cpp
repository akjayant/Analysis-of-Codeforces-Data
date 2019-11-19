#include<bits/stdc++.h>
using namespace std;
 
#define int long long
int t, n, ans;
string s;
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin >> t;
	while(t--){
		cin >> n >> s;
		ans = n;
		for(int i = 0; i < n; i++){
			if(s[i] == '1'){
				ans = max(ans, 2 * (n - i));
				break;
			}
		}
		for(int i = n - 1; i >= 0; i--){
			if(s[i] == '1'){
				ans = max(ans, 2 * (i + 1));
			}
		}
		cout << ans << "\n";
	}
}