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
		int n, m;
		cin >> n;
		int a[2] = {0}, b[2] = {0};
		for(int i = 1; i <= n; i++){
			int p;	cin >> p;
			a[p&1]++;
		}
		cin >> m;
		for(int i = 1; i <= m; i++){
			int q;	cin >> q;
			b[q&1]++;
		}
		int ans = a[0]*b[0] + a[1]*b[1];
		cout << ans << endl;
	}	
	return 0;
}