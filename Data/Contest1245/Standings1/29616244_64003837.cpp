#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
int dp[100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	dp[0]=1;
	dp[1]=1;

	string s;
	cin >> s;

	for(int i=2; i<=s.size(); ++i) {
		dp[i]=(dp[i-1]+dp[i-2])%MOD;
	}

	long long ans=1;

	for(int i=0, j=0; i<s.size(); i=j) {
		for(; j<s.size()&&s[j]==s[i]; ++j);
		if(s[i]=='u'||s[i]=='n') {
			ans=ans*dp[j-i]%MOD;
		}
		if(s[i]=='m'||s[i]=='w') {
			ans=0;
		}
	}

	cout << ans;

	return 0;
}