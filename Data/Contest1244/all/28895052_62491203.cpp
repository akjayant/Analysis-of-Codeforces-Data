#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,p,w,d,x,y;
void Exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b) {y=0,x=1; return;}
	Exgcd(b,a%b,y,x);
	y-=x*(a/b);
}
void f(ll &o,ll Mod)
{
	if(o>=Mod) o-=Mod;
	if(o<0) o+=Mod;
}
ll Mul(ll o,ll q,ll Mod)
{
	ll ans=0;
	while(q)
	{
		if(q&1) ans+=o,f(ans,Mod);
		o=o<<1;
		f(o,Mod); q=q>>1;
	}
	return ans;
}
ll gcd(ll a,ll b)
{
	while(b)
	{
		a%=b;
		swap(a,b);
	}return a;
}
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&p,&w,&d);
	ll dd=gcd(w,d);
	if(p%dd) {printf("-1\n"); return 0; }
	ll a=w/dd;
	ll b=d/dd; p/=dd;
	Exgcd(a,b,x,y);
	ll pro=Mul(y,p,a);
	ll pre=(p-pro*b)/a;
	if(pro+pre<=n&&pre>=0) printf("%I64d %I64d %I64d\n",pre,pro,n-pro-pre);
	else printf("-1\n");
	return 0;
}