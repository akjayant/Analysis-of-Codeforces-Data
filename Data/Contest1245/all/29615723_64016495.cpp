#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll p=1e9+7;
const int N=1e5;
char s[N+10];ll ans=1;
ll fac[N+10],ifac[N+10];

ll fpm(ll a,ll b)
{
	ll ret=1;
	for(;b;b>>=1) ret=(b&1)?ret*a%p:ret,a=a*a%p;
	return ret;
}

ll C(ll n,ll m)
{
	if(n>m) return 0;
	return fac[m]*ifac[n]%p*ifac[m-n]%p;
}

void calc(ll n)
{
	if(n<2) return ;
	--n;ll ret=0;
	for(int i=0;i<=n;++i) ret=(ret+C(i,n-i+1))%p;
 	ans=ans*ret%p;
}

int main()
{
	fac[0]=1;
	for(int i=1;i<=N;++i) fac[i]=fac[i-1]*i%p;
	ifac[N]=fpm(fac[N],p-2);
	for(int i=N;i>=1;--i) ifac[i-1]=ifac[i]*i%p;
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;++i) if(s[i]=='w'||s[i]=='m'){printf("0\n");return 0;};
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]!='u') calc(cnt),cnt=0;
		else ++cnt;
	};
	calc(cnt);
	cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]!='n') calc(cnt),cnt=0;
		else ++cnt;
	};
	calc(cnt);
	printf("%lld\n",ans);
	return 0;
}