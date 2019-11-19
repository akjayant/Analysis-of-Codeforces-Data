#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		string s;
		cin>>s;
		ll max1=0;
		max1=n;
		if(s[0]=='1'||s[n-1]=='1')
		{
			cout<<2*n<<endl;
			continue;
		}
		for(ll i=1;i<n;i++)
		{
			ll x=0;
			if(s[i]=='1')
			{
				x=2*(i+1);
				if(x<(2*(n-i)))
				{
					x=2*(n-i);
				}
			}
			if(max1<x)
			{
				max1=x;
				
			}
		}
		cout<<max1<<endl;
	}
	
}