#include<bits/stdc++.h>
#define ll long long
using namespace std;
int k,n,a[1010];
int main()
{
	ios::sync_with_stdio(false);
	cin>>k;
	while(k--)
	{
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)
			ans=max(ans,min(n-i+1,a[i]));
		cout<<ans<<endl;
	}
	return 0;
}
