#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
vector<int>ans;
const int mod=1e9+7;
int dp[maxn][2],p[maxn];
long long Ans;
int main(){
	Ans=1;
	cin >> s;
	int len=strlen(s);
	dp[1][0]=dp[0][0]=1;
	for (int i=2;i<=len;i++){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
		dp[i][1]=(dp[i-2][1]+dp[i-2][0])%mod;
	}
	if ((s[0]=='u'||s[0]=='n'))
		p[0]=1;
	for (int i=0;i<len;i++){
		if (s[i]=='m'||s[i]=='w'){
			cout << 0;
			return 0;
		}
	}
	for (int i=1;i<len;i++){
		p[i]=1;
		if (s[i]==s[i-1]){
			p[i]=p[i-1]+1;
		}else{
			ans.push_back(p[i-1]);
		}
		if (!(s[i]=='u'||s[i]=='n'))
			p[i]=0;
	}
	ans.push_back(p[len-1]);
	for (auto i:ans){
		Ans=Ans*(dp[i][0]+dp[i][1])%mod;
	}
	cout << Ans;
}