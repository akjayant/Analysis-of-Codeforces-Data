#include <bits/stdc++.h>
using namespace std;

#define ll long long 
ll exp(ll x,ll y,ll mod)
{
	ll res=1;
	while(y>0)
	{
		if(y%2==1)
		res=(res%mod*x%mod)%mod;
		y=y/2;
	x=(x%mod*x%mod)%mod;
	}
	return res;
	
}
int main()
{
	
	int n;
	cin>>n;
	vector<vector<int> > a(n,vector<int> (n));
	int dir=0;
	int l=1;
	for(int i=0;i<n;i++)
	{
		if(dir==0)
		{
			for(int j=0;j<n;j++)
			{
				a[j][i]=l;
				l++;
			}
			dir=1;
		}
		else
		{
			for(int j=n-1;j>=0;j--)
			{
				a[j][i]=l;
				l++;
			}
			dir=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
