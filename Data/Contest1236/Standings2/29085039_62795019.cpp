#include <cstdio>
#include <algorithm>
using namespace std;
#define N 510
int ans[N][N],n;
int main()
{
	scanf("%d",&n);
	for(int i=1,flag=1;flag^=1,i<=n;i++)
		for(int j=1;j<=n;j++)
			if(flag) ans[j][i]=(i-1)*n+j;
			else ans[n-j+1][i]=(i-1)*n+j;
	for(int i=1;i<=n;printf("\n"),i++) for(int j=1;j<=n;j++) printf("%d ",ans[i][j]);
}