#include <bits/stdc++.h>

using namespace std;
const int N=1e3+55;
int a[N];


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		int ans=0;
		for(int i=n-1;i>=0;i--)
		{
			ans=max(ans,min(n-i,a[i]));
		}
		cout<<ans<<endl;
	}
	
	
	
	
	return 0;
}
