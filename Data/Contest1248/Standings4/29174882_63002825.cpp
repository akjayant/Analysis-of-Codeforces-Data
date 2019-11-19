#include <bits/stdc++.h>

using namespace std;
#define lowbit( x ) (x&(-x))
#define debug( x ) cout<<#x<<" is "<<x<<endl;
typedef long long ll;
const int N = 1e5 + 5;
#define pi acos(-1.0)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
typedef pair < int , int > P;
typedef pair < ll , int > PL;
int n , m,a[N];
ll fac[N];
ll qs(ll a,int b)
{
	ll res =1;
	while(b)
	{
		if(b&1) res = res * a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return res;
}
ll Com(int a,int b)
{
	return fac[a]*qs(fac[a-b]*fac[b]%mod,mod-2)%mod;
}
int main () {
	scanf("%d%d",&n,&m);
	fac[0] = 1;
	for(int i = 1;i<=100000;++i) fac[i] = fac[i-1] * i % mod;
	ll ans = 0;
	for(int i = 0;i<=(n/2);++i)
	{
		int j = n - 2*i;
		ans = (ans + Com(i+j,i))%mod;
	}
	for(int i = 0;i<=(m/2);++i)
	{
		int j = m - 2*i;
		ans = (ans + Com(i+j,i))%mod;
	}
	ans = (ans - 1+mod)%mod;
	ans = ans*2%mod;
	printf("%lld\n",ans);
	return 0;
}
/*
 In the second example,  The cyclical shifts by 1 ,we get a string " ))(())()()((" ,but this string is incorrect.
 */