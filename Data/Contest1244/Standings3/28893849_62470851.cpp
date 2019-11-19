#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=1009;
LL T,n;
char s[N];
template<typename T>
inline void read(T &x)
{
	x=0;T w=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')w=-1;	c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-'0';	c=getchar();}
	x*=w;
}
int main()
{
	read(T);
	while(T--)
	{
		read(n);
		scanf("%s",s+1);
		LL l=n+1,r=0,ans=n;
		for(LL i=1;i<=n;++i)
		{
			if(s[i]=='1')
			{
				l=min(l,i);
				r=max(r,i);
			}
		}
		if(r)	ans=max(ans,2*max(max(l,n-l+1),max(r,n-r+1)));
		printf("%I64d\n",ans);
	}
	return 0;
}