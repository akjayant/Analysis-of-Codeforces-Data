#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define int long long 
using namespace std;
const int maxn = 1e5+10;
const int mod = 1e9+7;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}

int k,m,n;
char c[maxn];
int dp[maxn];
signed main(){
	scanf("%s",c+1);
	n=strlen(c+1);
	dp[0]=1;
	for(register int i=1;i<=n;i++){
		if(c[i]=='u' && c[i-1]=='u')(dp[i]=dp[i-1]+dp[i-2])%=mod;
		else if(c[i]=='n' && c[i-1]=='n')(dp[i]=dp[i-1]+dp[i-2])%=mod;
		else dp[i]=dp[i-1];
		if(c[i]=='m' || c[i]=='w'){puts("0");return 0;}
	}
	printf("%lld\n",dp[n]);
	return 0;
}