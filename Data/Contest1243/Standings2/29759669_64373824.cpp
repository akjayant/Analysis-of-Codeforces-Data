#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	long int t;
	cin>>t;
	while(t--)
	{
	    long int n;
	    cin>>n;
	    long int a[n];
	    for(long int i=0;i<n;i++)
	    cin>>a[i];
	    sort(a,a+n,greater<long int>());
	    long int ans=1;
	    for(long int i=1;i<n;i++)
	    {
	        ans=max(ans,min(a[i],i+1));
	    }
	    cout<<ans<<endl;
	}
	return 0;
}