#include <bits/stdc++.h>

using namespace std;

signed main() 
{
	int a,b,c,d,k;
	int T;
	scanf("%d",&T);
	while(T--)
	{
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
	int flag=0;
		for(int i=0;i<=k;i++)
	{
		if(i*c>=a&&(k-i)*d>=b)
		{
			flag=1;
			printf("%d %d\n",i,k-i);
			break;
		}
	}
	if(flag==0)printf("-1\n");
	}	
	return 0;
}