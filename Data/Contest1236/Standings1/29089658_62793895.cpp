#include<cstdio>
#include<algorithm>
using namespace std;
int n,i,j,k,gr[305][305],ty=0;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n*n;i+=n)
	{
		ty=!ty;
		if(ty==0)k=1;
		else k=n;
		for(j=i;j<i+n;j++)
		{
			gr[k][i/n+1]=j;
			if(ty==0)k++;
			else k--;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<n;j++)printf("%d ",gr[i][j]);
		printf("%d\n",gr[i][n]);
	}
	return 0;
}