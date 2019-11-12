#include<bits/stdc++.h>
using namespace std;
int a,b,c,test,ans;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&a,&b,&c);
		ans=0;
		for (int i=0;i<=a;i++)
		{
			for (int j=0;j<=c;j++)
			{
				if (2*i+j<=b && 2*j<=c) 
				{
					ans=max(ans,3*(i+j));
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}