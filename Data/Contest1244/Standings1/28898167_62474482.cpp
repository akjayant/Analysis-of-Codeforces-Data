#include<bits/stdc++.h>
#define FOR(i, x, y) for(int i = (x), i##END = (y); i <= i##END; ++i)
#define DOR(i, x, y) for(int i = (x), i##END = (y); i >= i##END; --i)
template<typename T, typename _T> inline bool chk_min(T &x, const _T y) {return y < x ? x = y, 1 : 0;}
template<typename T, typename _T> inline bool chk_max(T &x, const _T y) {return x < y ? x = y, 1 : 0;}
typedef long long ll;
ll n,p,w,d;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x);y-=a/b*x;
}

ll Exgcd(ll A,ll B,ll C)
{
	ll g,k1,k2;
	g=gcd(A,B);
	if(C%g)return -1;
	A/=g,B/=g,C/=g;
	exgcd(A,B,k1,k2);
	return ((k1%B)*(C%B)%B+B)%B;
}

int main()
{
	scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
	std::swap(w,d);
	ll x=Exgcd(w,d,p);
	if(x==-1)puts("-1");
	else
	{
		ll y=(p-x*w)/d;
		if(y<0||x+y>n)puts("-1");
		else printf("%lld %lld %lld\n",y,x,n-x-y);
	}
	return 0;
}
