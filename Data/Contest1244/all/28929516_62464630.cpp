#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
using namespace std;

int T,a,b,c,d,i,j,k,l;

int main()
{
//	freopen("a.in","r",stdin);
	
	scanf("%d",&T);
	for (;T;--T)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		
		a=(a-1)/c+1;
		b=(b-1)/d+1;
		
		if (a+b<=k)
		printf("%d %d\n",a,b);
		else
		printf("-1\n");
	}
}