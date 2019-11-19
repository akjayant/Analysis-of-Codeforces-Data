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
int T,A,B,C,D,K;
int main()
{
	T=read();
	while(T--)
	{
		A=read(),B=read(),C=read(),D=read(),K=read();
		int x=A/C+(A%C!=0),y=B/D+(B%D!=0);
		if(x+y>K) { printf("-1\n"); }
		else printf("%d %d\n",x,y);
	}
	return 0;
}