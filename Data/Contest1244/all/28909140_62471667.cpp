#include<bits/stdc++.h>
using namespace std;
char a[1007];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",a+1);
		int left=-1,right=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='1')
			{
				right=i;
				if(left==-1)
					left=i;
			}			
		}
		if(left==-1)
			printf("%d\n",n);
		else
		{
			int ans1=2*(n-left+1);
			int ans2=2*right;
			printf("%d\n",max(ans1,ans2));
		}
	}
}