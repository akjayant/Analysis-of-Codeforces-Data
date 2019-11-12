#include<bits/stdc++.h>
using namespace std;
int a[400][400];
int main()
{
	int n;
	cin>>n;
	int flag=1,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(flag)
		for(int j=1;j<=n;j++)
		{
			a[j][i]=++cnt;
			flag=0;
		}
		else 
		{
			for(int j=n;j>0;j--)
			{
				a[j][i]=++cnt;
				flag=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}