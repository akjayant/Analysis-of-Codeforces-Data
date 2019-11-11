#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int Mod=1e9+7;
inline void ad(int &x,int y){
	x+=y;
	if (x>=Mod) x-=Mod;
}
int n,flag,dp[N];
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	dp[0]=1;
	for (int i=0;i<n;++i){
		ad(dp[i+1],dp[i]);
		if (i+2<=n && s[i+1]=='u' && s[i+2]=='u')
			ad(dp[i+2],dp[i]);
		if (i+2<=n && s[i+1]=='n' && s[i+2]=='n')
			ad(dp[i+2],dp[i]);
		if (s[i+1]=='m' || s[i+1]=='w') flag=1;
	}
	if (flag) dp[n]=0;
	printf("%d\n",dp[n]);
    return 0;
}
