#include <bits/stdc++.h>
using namespace std;
 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define left  (2*idx)+1
#define right (2*idx)+2
#define pb push_back
#define ll long long
#define all(x) x.begin(),x.end()
 

const ll MOD = (ll)(1e9 + 7); 
const ll N = 0;

int main()
{
	FIO;
	string s;
	cin >> s;
	int n = s.length();
	ll dp[n+1];
	dp[n] = 1;
	dp[n-1] = 1;
	if(s[n-1] == 'w' || s[n-1] == 'm') {
		cout << 0 << "\n";
		return 0;
	}
	for(int i=n-2; i>=0; i--) {
		if(s[i] == 'w' || s[i] == 'm') {
			cout << 0 << "\n";
			return 0;
		}
		if(s[i]!='u' && s[i]!='n') {
			dp[i] = dp[i+1];
			continue;
		} else if(s[i]!=s[i+1]) {
			dp[i] = dp[i+1];
			continue;
		} else {
			dp[i] = (dp[i+2] + dp[i+1]) % MOD;
		}
	}
	cout << dp[0] << "\n";
	return 0;	
}	