#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll=long long;

main()
{
	ll t,n,m,num;
	
	cin>>t;
	
	while(t--)
	{
		ll o1=0,o2=0,e1=0,e2=0,ans=0;
		cin>>n;
		
		for(int i=0;i<n;i++)
		{
			cin>>num;
			
			if(num%2)
			o1++;
			else
			e1++;
		}
		
		cin>>m;
		
		for(int i=0;i<m;i++)
		{
			cin>>num;
			
			if(num%2)
			o2++;
			else
			e2++;
		}
		
		cout<<o1*o2+e1*e2<<endl;
	}
}