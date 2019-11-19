#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
namespace Dango
{
	int t,a,b,c,d,k,x,y;
	int ans;
	int read()
	{
		int x=0,f=0;
		char ch=getchar();
		while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
		while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	void solve()
	{
		a=read();b=read();c=read();d=read();k=read();
		x=(a+c-1)/c;y=(b+d-1)/d;
		x+y>k?printf("-1\n"):printf("%d %d\n",x,y);
	}
	int work()
	{
		t=read();
		for(int i=1;i<=t;i++)
			solve();
		return 0;
	}
}
int main()
{
	return Dango::work();
}