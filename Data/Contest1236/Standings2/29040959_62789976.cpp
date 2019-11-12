#include<bits/stdc++.h>
using namespace std;
int mark=0;
vector<int>v[3001];
signed main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n*n;i+=n)
	{
		if(mark==1)
		{
			for(int j=1;j<=n;j++)
				v[j].push_back(i+j-1);
		}
		else
			for(int j=1;j<=n;j++)
				v[n-j+1].push_back(i+j-1);
		mark^=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)
			printf("%d ",v[i][j]);
		printf("\n");
	}
	return 0;
}
