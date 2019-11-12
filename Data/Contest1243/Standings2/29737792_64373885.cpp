#include "bits/stdc++.h"
#define int long long
using namespace std;
int32_t main(){
	int q;cin>>q;
	while(q--)
	{
		int n;cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			ans=max(ans,min(a[i],n-i));
		}
		cout<<ans<<endl;
	}
    
}