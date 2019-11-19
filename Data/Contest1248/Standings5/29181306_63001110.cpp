#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
const int mod = 1e9+7;
inline char get(){
	static char buf[30000],*p1=buf,*p2=buf;
	return p1==p2 && (p2=(p1=buf)+fread(buf,1,30000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	register char c=get();register int f=1,_=0;
	while(c>'9' || c<'0')f=(c=='-')?-1:1,c=get();
	while(c<='9' && c>='0')_=(_<<3)+(_<<1)+(c^48),c=get();
	return _*f;
}
int n,m;
int dp[maxn];
signed main(){
	//freopen("1.txt","r",stdin);
	n=read(),m=read();
	int ans=0;
	dp[0]=1;
	if(n>m)swap(n,m);
	for(register int i=1;i<=n;i++)dp[i]=dp[i-1]+dp[i-2],dp[i]%=mod;
	dp[n]%=mod;
	ans+=dp[n]%mod;
	ans%=mod;
	dp[0]=1;
	for(register int i=1;i<=m;i++)dp[i]=dp[i-1]+dp[i-2],dp[i]%=mod;
	ans+=dp[m]%mod;
	ans%=mod;
	cout<<(((ans-1+mod)%mod)*2)%mod<<endl;
	return 0;
}