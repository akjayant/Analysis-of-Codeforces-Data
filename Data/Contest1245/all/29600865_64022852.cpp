#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iostream>
#define test freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
char s[maxn];
LL fac[maxn];
LL powmod(LL a,LL b)
{
	LL res=1;
	while(b)
	{
		if(b&1) res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
LL C(int a,int b)
{
	LL t=powmod(fac[b]*fac[a-b]%mod,mod-2);
	return fac[a]*t%mod;
}
LL solve(int n)
{
	int lim=n/2;
	LL res=1;
	for(int i=1;i<=lim;++i)
	{
		res=(res+C(n-i,i))%mod;
	}
	return res;
}
int main()
{
	//test
	scanf("%s",s);
	fac[0]=1;
	for(int i=1;i<maxn;++i) fac[i]=fac[i-1]*i%mod;
	int cntu=0,cntn=0;
	LL ans=1;
	for(int i=0;s[i];++i)
	{
		if(s[i]=='u') ++cntu;
		else if(s[i]=='n') ++cntn;
		if(s[i]=='m'||s[i]=='w') {cout<<0;return 0;}
		if(s[i]!='u') ans=(ans*solve(cntu))%mod,cntu=0;
		if(s[i]!='n') ans=(ans*solve(cntn))%mod,cntn=0;
	}
	ans=(ans*solve(cntu))%mod;
	ans=(ans*solve(cntn))%mod;
	cout<<ans;
	return 0;
}