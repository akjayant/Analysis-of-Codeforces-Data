#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll=long long;


main()
{
	ll n;
	cin>>n;
	
	vector<ll> v[n+1];
	int dir=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dir==0)
			v[j].push_back((i-1)*n+j);
			else
			v[n+1-j].push_back((i-1)*n+j);
		}
		
		dir=1-dir;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<v[i][j]<<" ";
		}
		
		cout<<endl;
	}
}