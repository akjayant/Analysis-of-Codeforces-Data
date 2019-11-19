#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll=long long;

main()
{
	ll n;
	
	cin>>n;
	
	vector<ll> v(n);
	
	for(int i=0;i<n;i++)
	cin>>v[i];
	
	sort(v.begin(),v.end());
	
	ll temp1=0,temp2=0;
	
	for(int i=n-1;i>=0;i--)
	{
		if(i>=n/2)
		temp1+=v[i];
		else
		temp2+=v[i];
	}
	
	cout<<temp1*temp1+temp2*temp2;
}