#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	scanf("%d",&t);
	int e,k,a,b,c,d;
	while(t--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		if(a%c!=0)a+=c;
		a/=c;
		e=k-a;
		if(e*d>=b)
		{
			printf("%d %d\n",a,e);
		}
		else
		printf("-1\n");
	}
	return 0;
}