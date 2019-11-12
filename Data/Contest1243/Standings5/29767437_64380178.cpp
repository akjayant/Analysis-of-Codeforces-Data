#include<iostream>
#include<cstdio>
using namespace std;
int a[1005];
int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		int l=1,r=n,res;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			int cnt=0,f=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]>=mid)cnt++;
				if(cnt>=mid){f=1;break;}
			}
			if(f)l=mid+1,res=mid;
			else r=mid-1;
		}
		printf("%d\n",res);
	}
	return 0;
}
