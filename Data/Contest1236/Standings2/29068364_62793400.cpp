#include<bits/stdc++.h>
using namespace std;

const int maxn=305;
int n,w,ww,a[maxn][maxn];

int main()
{
	scanf("%d",&n);
	w=n/2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)a[i][j]=(i-1)*w+j;
		for(int j=n;j>=n-w+1;j--)a[i][j]=n*n+1-a[i][n+1-j];
	}
	ww=w*n;
	if(n%2==1)
	{
		for(int i=1;i<=n;i++)
		{
			a[i][w+1]=ww+i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}