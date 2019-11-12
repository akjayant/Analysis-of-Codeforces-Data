#include <bits/stdc++.h>
using namespace std;

#define ll long long 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		ll ans=0;
		int temp=min(c/2,b);
		b-=temp;
		ans+=3*temp;
		temp=min(b/2,a);
		ans+=3*temp;
		cout<<ans<<endl;
	}
	return 0;
}
