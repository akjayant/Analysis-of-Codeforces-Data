#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a[n];
		for(int i=0;i<n;i++)	cin>>a[i];
		sort(a,a+n);
		ll count=1,ans = 0;
		for(int i=n-1;i>=0;i--){
			if(a[i]>=count)	ans++;
			else break;
			count++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}