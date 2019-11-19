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
ll n,t,m;
ll p[M],q[M],ap,aq,bp,bq;//a -> odd  b-> ou
int main()
{
	ll i,j;
	t=read();
	while(t--)
	{
		ap=0,aq=0,bp=0,bq=0;
		n=read();
		for(i=1;i<=n;i++)
		{
			p[i]=read();
			if(p[i]%2==0)
			bp++;
			else 
			ap++;
		}
		m=read();
		for(i=1;i<=m;i++)
		{
			q[i]=read();
			if(q[i]%2==0)
			bq++;
			else 
			aq++;
		}
		
		
		ll ans=0;
		ans=bp*bq+ap*aq;
		printf("%lld\n",ans);
	}
	
	
	
	return 0;
}