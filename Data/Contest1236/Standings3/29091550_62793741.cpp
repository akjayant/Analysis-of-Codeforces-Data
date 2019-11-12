#include <bits/stdc++.h>
using namespace std;

int a[1024][1024];

int main()
{
	int n;
	cin>>n;
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (i%2)
			for (int j=1;j<=n;j++) a[j][i]=++cnt;
		else
			for (int j=n;j>=1;j--) a[j][i]=++cnt;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<n;j++)
			cout<<a[i][j]<<' ';
		cout<<a[i][n]<<endl;
	}
	return 0;
}