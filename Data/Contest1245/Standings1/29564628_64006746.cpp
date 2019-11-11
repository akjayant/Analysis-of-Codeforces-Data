#include<bits/stdc++.h>
#define maxn 100005
#define maxm 500005
#define inf 0x7fffffff
#define mod 1000000007
#define ll long long

using namespace std;
int dp[maxn]; char str[maxn];

inline int read(){
    int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

inline int mo(int x){return x>=mod?x-mod:x;}

int main(){
	scanf("%s",str+1);
	int n=strlen(str+1);
	dp[0]=1; bool flag=0;
	for(int i=1;i<=n;i++){
		if(str[i]=='w' || str[i]=='m'){flag=1;break;}
		dp[i]=dp[i-1];
		if(str[i]=='n' && str[i-1]=='n') dp[i]=mo(dp[i]+dp[i-2]);
		if(str[i]=='u' && str[i-1]=='u') dp[i]=mo(dp[i]+dp[i-2]); 
	}
	if(flag) cout<<0<<endl;
	else cout<<dp[n]<<endl;
	return 0;
}
