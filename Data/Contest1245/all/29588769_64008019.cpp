#include <bits/stdc++.h>
using namespace std;
const int N =1e5+9;
const int mod = 1e9+7;
typedef long long ll;


int main() {  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    int l = s.length();
    bool pos =true;
    for(int i=0;i<l;i++){
    	if(s[i]=='m'||s[i]=='w') pos = false;
	}
	ll dp[l+1]; 
	dp[0]=dp[1]=1;
	for(int i=2;i<=l;i++){
		dp[i]=dp[i-1];
		if(s[i-1]==s[i-2]&&(s[i-1]=='u'||s[i-1]=='n')) 
			dp[i] = (dp[i-1]+dp[i-2])%mod;
	}
	if(!pos) dp[l] = 0;
	//for(int i=0;i<l;i++) cout<<dp[i]<<" ";
	cout<<dp[l];	
}