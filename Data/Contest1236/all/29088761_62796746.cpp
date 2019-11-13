#include<bits/stdc++.h>
using namespace std;
typedef long long i64;

int a[302][302];

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int x=n*n;
	for(i=1;i<=n;i++)
		if(i&1)
			for(j=1;j<=n;j++)
				a[j][i]=x--;
		else
			for(j=n;j;j--)
				a[j][i]=x--;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}