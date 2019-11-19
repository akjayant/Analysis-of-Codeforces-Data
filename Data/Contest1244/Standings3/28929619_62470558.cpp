#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c,d,k,T; 
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		if((a-1)/c+1+(b-1)/d+1>k) puts("-1");
		else printf("%d %d\n",(a-1)/c+1,(b-1)/d+1);
	}
	return 0;
}
