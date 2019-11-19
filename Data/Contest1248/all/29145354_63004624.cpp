#include <bits/stdc++.h>
using namespace std;
int M=1e9+7;
int main()
{
	int n,m;
	cin>>n>>m;
	long long int a[n],b[m];
	a[0]=1;
	b[0]=1;
	if (n>1)
	{
		a[1]=2;
	}	
	if (m>1)
	{
		b[1]=2;
	}
	for (int i = 2; i < n; ++i)
	{
		a[i]=(a[i-1]+a[i-2])%M;
	}
	for (int i = 2; i < m; ++i)
	{
		b[i]=(b[i-1]+b[i-2])%M;
	}
	//cout<<a[n-1]<<" "<<b[n-1]<<endl;
	a[n-1]=(a[n-1]*2)%M;
	b[m-1]=(b[m-1]*2)%M;
	cout<<(a[n-1]+b[m-1]-2+M)%M<<endl;	

}