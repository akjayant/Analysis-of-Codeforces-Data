#include<bits/stdc++.h>
using namespace std;

vector<int> lin[310];
int n;
int main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i%2==1) lin[j].push_back((i-1)*n+j);
			 else lin[j].push_back((i-1)*n+n+1-j);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",lin[i][j]);
		}
		printf("\n");
	}
	return 0;
}
