#include<bits/stdc++.h>
#define LL long long
using namespace std;
//const LL N=;
LL T,a,b,c,d,k;
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
		read(a);read(b);read(c);read(d);read(k);
		bool is=0;
		for(LL i=0;i<=k;++i)
		{
			if(i*c>=a&&(k-i)*d>=b)
			{
				is=1;
				printf("%I64d %I64d\n",i,k-i);
				break;
			}
		}
		if(!is)	printf("-1\n");
	}
	return 0;
}