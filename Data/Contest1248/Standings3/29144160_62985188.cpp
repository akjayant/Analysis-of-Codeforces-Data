#include<bits/stdc++.h>
#define ll long long
#define clr(c) memset(c,0,sizeof(c))
const int M=1e5+10;
const int mod=1e9+7;
using namespace std;
inline ll read()
{
	ll b=1,sum=0; char c=getchar();
	while(!isdigit(c)){if(c=='-') b=-1; c=getchar();}
	while(isdigit(c)){sum=sum*10+c-48;c=getchar();}
	return b*sum;
} 
ll n;
ll a[M];
int main()
{
	ll i,j;
	n=read();
	for(i=1;i<=n;i++)
	{
		a[i]=read();
	}
	
	sort(a+1,a+1+n);
	ll x=0,y=0;
	for(i=1;i<=n/2;i++)
	{
		y+=a[i];
	}
	for(;i<=n;i++)
	{
		x+=a[i];
	}
	
	ll ans=x*x+y*y;
	printf("%lld",ans);
	return 0;
}