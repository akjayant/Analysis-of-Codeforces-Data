#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ans[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i%2==0)
			{
				ans[i][j]=(n*i)+j+1;
			}
			else
			{
				ans[i][j]=(n*i)+n-j;
			}
		}
	}
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<n;i++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}