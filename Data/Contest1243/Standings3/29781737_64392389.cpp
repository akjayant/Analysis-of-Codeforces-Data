#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int t,n,a[N];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		sort(a+1,a+n+1);
		ll ma=0,ans=-1;
		for(int i=1;i<=n;i++)
		{
			ll res=n-i+1;
			ll zz=min(res,(ll)a[i]);
			ans=max(ans,zz);
		}
		cout<<ans<<endl;
	}
}