#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define endl "\n"
 

int pow1(int n, int p)
{
	if(p==0)	return 1;
	int x=pow1(n, p/2);
	x=(x*x)%mod;
	if(p%2==0)
		return x;
	else
		return (x*n)%mod;
}

int32_t main()
{
	fast;
	int n;
	cin>>n;
	vector<vector<int>> v(n+1);
	int f=0;
	int x=1;
	for(int i=0;i<n;i++)
	{
		if(f==0)
		{
			for(int j=0;j<n;j++)
			{
				v[j].push_back(x);
				x++;
			}
			f=1;
		}
		else
		{
			for(int j=n-1;j>=0;j--)
			{
				v[j].push_back(x);
				x++;
			}
			f=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<v[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}