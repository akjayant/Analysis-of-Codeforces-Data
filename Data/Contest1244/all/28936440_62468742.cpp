#include<bits/stdc++.h>
using namespace std;
int main()
{
 	int t;
 	scanf("%d",&t);
 	while(t--)
 	{
		int a,b,c,d;
		int k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int x=ceil(1.0*a/c);
		int y=ceil(1.0*b/d);
		if(x+y>k) puts("-1");
		else printf("%d %d\n",x,y);
	}
}
