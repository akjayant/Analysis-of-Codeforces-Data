#include<iostream>
using namespace std;
long long t,n,m;
int main()
{
	cin>>t;
	while (t--)
	{
		long long ou1=0,ji1=0,ji2=0,ou2=0;
		cin>>n;
		for (long long i=1;i<=n;i++)
		{
			long long x;
			cin>>x;
			if (x%2) ji1++;
			else ou1++;
		}
		cin>>m;
		for (long long i=1;i<=m;i++)
		{
			long long x;
			cin>>x;
			if (x%2) ji2++;
			else ou2++;
		}
		cout<<ji1*ji2+ou1*ou2<<endl;
	}
} 