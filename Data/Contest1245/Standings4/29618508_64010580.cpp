#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int dp[100000 + 10];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	string s;
	cin >> s;
	dp[0] = 1;
	if(s[0] == s[1] && (s[1] == 'u' || s[1] == 'n'))
		dp[1] = 2;
	else
		dp[1] = 1;
	for(int i = 2; i < (int)s.size(); i++)
		if(s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n'))
			dp[i] = (dp[i - 2] + dp[i - 1])%M;
		else
			dp[i] = dp[i - 1];
	for(int i = 0; i < (int) s.size(); i++)
		if(s[i] == 'm' || s[i] == 'w'){
			cout << 0;
			return 0;
		}
	cout << dp[s.size() - 1] % M;
	
	
	return 0;
}
