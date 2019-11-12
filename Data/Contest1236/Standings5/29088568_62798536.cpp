#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
int main()
{
	ll n;
	cin>>n;
	vector<ll> v[n];
	bool flag=true;
	ll r=n*n;
	ll l=1;
	while(l<r)
	{
		for(int i=0;i<n;++i)
		{
			if(flag)
				v[i].pb(r--);
			else
				v[i].pb(l++);
		}
		flag=!flag;
	}
	for(int i=0;i<n;++i)
	{
		for(ll c:v[i])
			cout<<c<<" ";
		cout<<endl;
	}
	return 0;
}