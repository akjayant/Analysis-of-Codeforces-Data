/*input
4
5
00100
8
00000000
5
11111
3
110

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() {
	IOS;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = n;
		for(int i = 0 ;i < n ; i++){
			if(s[i] == '1'){
				ans = max(ans,2*(i+1));
				ans = max(ans,2*(n-i));
			}
		}
		cout << ans << endl;
	}

return 0;
}
