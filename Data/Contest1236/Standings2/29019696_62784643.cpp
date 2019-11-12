#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
 
signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;	cin >> t;
	while(t--){
		int a, b, c, ans = 0;
		cin >> a >> b >> c;
		while(c >= 2 && b > 0){
			ans += 3;
			c -= 2;
			b--;
		}
		while(b >= 2 && a > 0){
			ans += 3;
			b -= 2;
			a--;
		}
		cout << ans << endl;
	}	
	return 0;
}