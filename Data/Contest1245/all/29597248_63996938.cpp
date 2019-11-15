#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
}
int T,a,b;
int main()
{
	T=read();
	while(T--)
	{
		a=read(),b=read(); int GG=0;
		for(int i=2;i<=min(a,b);i++)
			if((a%i==0)&&(b%i==0))
			{
				GG=1; break;
			}
		if(GG) printf("Infinite\n");
		else printf("Finite\n");
	}
	return 0;
}