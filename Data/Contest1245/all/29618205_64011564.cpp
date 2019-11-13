#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
string s;
int dp[100100];

int main(){
	cin >> s;
	n = s.size();
	rep(i, n){
		if(s[i] == 'w' || s[i] == 'm'){
			cout << "0" << endl;
			return 0;
		}
	}
	dp[0] = 1;
	if(s[1] == s[0] && (s[1] == 'u' || s[1] == 'n')) dp[1] = 2;
	else dp[1] = 1;
	for(int i = 2; i < n; i++){
		dp[i] = dp[i-1]; 
		if(s[i] == 'u' || s[i] == 'n'){
			if(s[i] == s[i-1]){
				dp[i] += dp[i-2];
				dp[i] %= 1000000007;
			}
		}
	}
	cout << dp[n-1] << endl;
	return 0;
}
