#include <bits/stdc++.h>
 
#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define all(s) s.begin(),s.end()
//#define int long long
 
using namespace std;
 
const int N = (2e5 + 12);
const int mod = (1e9 + 7);
const int INF = (0x3f3f3f3f);
 
void solve(){
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	int x = a + (c - 1);
	x /= c;
	int y = b + (d - 1);
	y /= d;
	if(x + y <= k){
		 cout << x << " " << y << endl;
	}
	else{
		cout << -1 << endl;
	}
}
main()
{
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
