#include <bits/stdc++.h>
#define int long long
#define INF 1000000007
using namespace std;

int dp[100010];

signed main()
{
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	dp[0]=1;dp[1]=1;
	for(int i=2;i<=s.size();i++){dp[i]=dp[i-1]+dp[i-2];dp[i]%=INF;}
	for(int i=0;i<s.size();i++){
		if(s[i]=='w'){
			cout<<0<<endl;
			return 0;
		}
		if(s[i]=='m'){
			cout<<0<<endl;
			return 0;
		}
	}
	int ans=1,cnt=1;
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1]) cnt++;
		else{
			if(s[i-1]=='u'||s[i-1]=='n'){
				ans*=dp[cnt];
				ans%=INF;
			}
			cnt=1;
		}
	}
	if(s[s.size()-1]=='u'||s[s.size()-1]=='n'){
		ans*=dp[cnt];
		ans%=INF;
	}
	cout<<ans<<endl;
	return 0;
}