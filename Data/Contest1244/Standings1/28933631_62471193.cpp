#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	long long ans=0;
	for(cin>>T;T--;cout<<ans<<endl)
	{
		long long n;
		cin>>n;
		ans=n;
		string a;
		cin>>a;
		for(long long i=0;i<a.length();i++)
		{
			if(a[i]=='1')
			{
				ans=max(ans,n+1);
				ans=max(ans,2*i+2);
				ans=max(ans,2*(n-i));
			}
		}
	}
}

