#include <bits/stdc++.h>
using namespace std;
int n,a[333][333];
int main()
{
	scanf("%d",&n);
	for(int j=1;j<=n;j++)
	{
		int st=j,num=(j-1)*n+1;
//		for(int i=st;i<=n;i++)
//			a[i][j]=num++;
//		for(int i=1;i<st;i++)
//			a[i][j]=num++;
		if(j&1)for(int i=1;i<=n;i++)
			a[i][j]=num++;
		else for(int i=n;i>=1;i--)
			a[i][j]=num++;
		
	}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			if(i!=j)
//			{
//				int ans=0;
//				for(int k=1;k<=n;k++)
//					for(int l=1;l<=n;l++)
//						ans+=a[i][k]>a[j][l];
//				printf("%d %d %d\n",i,j,ans);
//			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			printf("%d%c",a[i][j]," \n"[j==n]);
	return 0;
}