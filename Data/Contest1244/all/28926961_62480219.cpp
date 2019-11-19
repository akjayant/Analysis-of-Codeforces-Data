#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	ll n,p,d,w;
	cin>>n>>p>>w>>d;
	for(int i=0;i<=100000;i++)
	{
		if((p-i*d)%w==0)
		{
			ll x=(p-i*d)/w;
			if(i+x<=n && x>=0)
			{
				cout<<x<<' '<<i<<' '<<n-i-x<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
}