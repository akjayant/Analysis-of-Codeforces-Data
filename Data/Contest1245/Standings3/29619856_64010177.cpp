#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int mod = 1e9+7;
const int maxn = 1e5+5;
char s[maxn];
int dp[maxn][2];
int main(){
	scanf("%s",s+1);
	int len = strlen(s+1);
	dp[0][0]=1;
	int flag=0;
	for(int i=1;i<=len;i++){
		if(s[i]=='m'||s[i]=='w')flag=1;
		dp[i][0]=(dp[i-1][1]+dp[i-1][0])%mod;
		dp[i][1]=0;
		if(s[i]=='u'){
			if(s[i-1]=='u')dp[i][1]=(dp[i-2][0]+dp[i-2][1])%mod;
		}
		if(s[i]=='n'){
			if(s[i-1]=='n')dp[i][1]=(dp[i-2][0]+dp[i-2][1])%mod;
		}
	}
	if(flag)puts("0");
	else cout<<(dp[len][0]+dp[len][1])%mod<<endl;
	return 0;
}