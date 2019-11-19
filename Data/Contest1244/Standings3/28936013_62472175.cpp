#include <bits/stdc++.h>
 
#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define all(s) s.begin(),s.end()
//#define int long long
 
using namespace std;
 
const int N = (2e3 + 12);
const int mod = (1e9 + 7);
const int INF = (0x3f3f3f3f);

int sf[N], pf[N];
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = "." + s;
	for(int i = 0;i <= n + 1; i++){
		sf[i] = 0;
		pf[i] = 0;
	}
	for(int i = 1;i <= n; i++){
		pf[i] += pf[i - 1] + 1;
	}
	for(int i = n;i >= 1; i--){
		sf[i] = sf[i + 1] + 1;
	}
	int ans = n;
	for(int i = 1;i <= n; i++){
		if(s[i] == '1'){
			ans = max(ans,pf[i] + sf[i]);
			ans = max(ans,pf[i] * 2);
			ans = max(ans,sf[i] * 2);
		}
	}
	cout << ans << endl;
}
main()
{
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
