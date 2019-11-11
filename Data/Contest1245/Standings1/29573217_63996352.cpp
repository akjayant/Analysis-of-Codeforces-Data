#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
using namespace std;

int T,a,b,i,j,k,l;

int gcd(int n,int m)
{
	int r=n%m;
	
	while (r)
	{
		n=m;
		m=r;
		r=n%m;
	}
	
	return m;
}

int main()
{
//	freopen("a.in","r",stdin);
	
	scanf("%d",&T);
	for (;T;--T)
	{
		scanf("%d%d",&a,&b);
		
		if (gcd(a,b)==1)
		printf("Finite\n");
		else
		printf("Infinite\n");
	}
}