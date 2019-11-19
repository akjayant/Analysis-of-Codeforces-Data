#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m,k,a,b,c,d;

int main()
{
	scanf("%d",&n);
	for(;n;n--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&m);
		int k=a/c;
		if(a%c) k++;
		int g=b/d;
		if(b%d) g++;
		if(k+g>m) printf("-1\n");
		else printf("%d %d\n",k,g);
	}
}