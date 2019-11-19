#include "bits/stdc++.h"
#define int long long
using namespace std;
int32_t main(){
	int q;
	q=1;
	while(q--)
	{
		int n,ans;cin>>n;
		int c=0;
		for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				while(n%i==0)
					n/=i;
					c++;
				ans=i;
				break;

			}
		}
		if(n>1)
		{
			c++;
			ans=n;
		}
		if(c>1)
			ans=1;
		cout<<ans<<"\n";


	}
    
}