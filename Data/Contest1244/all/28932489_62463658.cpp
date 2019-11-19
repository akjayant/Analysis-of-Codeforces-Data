#include<bits/stdc++.h>
using namespace std;

#define int long long
int t, a, b, c, d, k;

signed main(){
	ios_base::sync_with_stdio(0);
	cin >> t;
	while(t--){
		cin >> a >> b >> c >> d >> k;
		if(((a + c - 1) / c) + ((b + d - 1) / d) <= k) cout << (a + c - 1) / c << " " << (b + d - 1) / d;
		else cout << "-1";
		cout << endl;
	}
}