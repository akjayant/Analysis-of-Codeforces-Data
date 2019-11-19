#include<bits/stdc++.h>
using namespace std;
int T;
int a,b,c,d,k;
int main()
{
	scanf("%d",&T);
while(T--)
{
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
	int x=a/c,y=b/d;
	if(a%c)x++;if(b%d)y++;
	if(x+y>k)puts("-1");
	else printf("%d %d\n",x,y);
}
	return 0;
}
