#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("E:\\Gokul\\atomic_gpp", "r", stdin);
	freopen("E:\\Gokul\\atomic_gpp", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<long long>a(n);
	for(int i=0;i<n;i++)
	    cin>>a[i];
	sort(a.begin(),a.end());
	
	    ll ans=0,sum=0;
	    for(int i=0;i<n/2;i++)
	        ans+=a[i];
	   for(int i=n/2;i<n;i++)
	        sum+=a[i];
	   sum*=sum;
	   ans*=ans;
	   ans+=sum;
	   cout<<ans;
	
	return 0;
}