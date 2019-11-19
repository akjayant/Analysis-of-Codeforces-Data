#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll n, m, k, ans, mod=1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, temp=0;
	ll p, d, w;
	cin>>n>>p>>w>>d;
	temp=__gcd(d, w);
	if(p%temp)
	{
		cout<<-1;
		return 0;
	}
	p/=temp;
	d/=temp;
	w/=temp;
	for(i=0;i<w;i++)
	{
		if(p<d*i) break;
		if((p-d*i)%w==0)
		{
			if(i+(p-d*i)/w>n)
				cout<<"-1";
			else cout<<(p-d*i)/w<<' '<<i<<' '<<n-i-(p-d*i)/w;
			return 0;
		}
	}
	cout<<-1;
}