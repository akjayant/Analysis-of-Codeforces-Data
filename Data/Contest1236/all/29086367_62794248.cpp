#include<bits/stdc++.h>

using namespace std;
int n;
int opt[305][305];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	cin>>n;
	for(j=1;j<=n;j++)
		for(i=1;i<=n;i++)
		{
			if(j%2==0) opt[i][j]=i+n*(j-1);
			else opt[i][j]=(n-i+1)+n*(j-1);
		}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",opt[i][j]);
		putchar('\n');
	}
	return 0;
}
