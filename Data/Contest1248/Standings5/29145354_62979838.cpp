#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long int n,m,a[2][2];
		cin>>n;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				a[i][j]=0;
			}
		}
		for (int i = 0,t; i < n; ++i)
		{
			cin>>t;
			a[0][t%2]++;
		}
		cin>>m;
		for (int i = 0,t; i < m; ++i)
		{
			cin>>t;
			a[1][t%2]++;
		}
		cout<<a[0][0]*a[1][0]+a[0][1]*a[1][1]<<endl;

	}
}