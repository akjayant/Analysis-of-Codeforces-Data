#include<bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back
#define ll long long
using namespace std;
 
const int INF = 1e9;
const long long LINF = 1e18;
 
void test(){
 
}
 
const int MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	vector<ll> dp((int)s.size() + 2);
	dp[0] = 1;	
	dp[1] = 1;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'm' || s[i] == 'w'){
			cout << 0;
			return 0;
		}
	}
	for(int i = 2; i <= s.size(); i++){
		if((s[i-1] == 'u' && s[i-2] == 'u')||(s[i-1] == 'n' && s[i-2] == 'n')){
			dp[i] = (dp[i-2] + dp[i-1]) % MOD;
		} else dp[i] = dp[i-1];
	} 
	cout << dp[s.size()];
}