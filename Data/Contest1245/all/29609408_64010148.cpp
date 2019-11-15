#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int mod=1e9+7;
const int N=1e5+10;
char s[N];
LL dp[N];
int main(){
	dp[1]=dp[0]=1;
	for(int i=2;i<N;i++)dp[i]=(dp[i-1]+dp[i-2])%mod;
	scanf("%s",&s);
	LL ans=1;int len=strlen(s);
	for(int i=0;s[i];i++){
		if(s[i]=='w'||s[i]=='m'){
			printf("0\n");return 0;
		}
	}
	for(int i=0;s[i];){
		if(s[i]!='n'&&s[i]!='u'){i++;continue;}
		int l=i;
		while(l<len&&s[l]==s[i]) l++;
		ans=(ans*dp[l-i])%mod;
		i=l;
	}
	printf("%lld\n",ans);
	return 0;
}