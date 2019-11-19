#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	long long int n;
	cin>>n;
	long long int ans=n;
	for(long long int i=2;i*i<=n;i++)
	{
	    if(n%i==0)
	    {
	        ans=__gcd(ans,i);
	        ans=__gcd(ans,n/i);
	    }
	}
	cout<<ans;
	return 0;
}