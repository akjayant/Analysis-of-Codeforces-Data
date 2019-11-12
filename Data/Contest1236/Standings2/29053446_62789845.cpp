#include<cstdio>

int a[305][305];
int main()
{
	int n;
	scanf("%d",&n);
	int cnt=n*n,i=1,j=1,ln=0;
	while(ln<cnt)
	{
		a[i][j]=++ln;
		if(j&1)
		{
			if(i<n) i++;
			else j++;	
		}
		else
		{
			if(i>1) i--;
			else j++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
}
