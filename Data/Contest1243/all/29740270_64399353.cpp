#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pp pair<ll,ll>
#define pq_min priority_queue<ll,vector<ll>,greater<ll>>
#define pq_max priority_queue<ll>
#define forx(i,a,b) for(ll i=0;i<a;i++)
#define ld long double
const ll mod=1e9 + 7;

int main()
{
	ll n;
	cin>>n;
	vector<ll> g;
	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			g.pb(i);
			if(i*i!=n)
			{
				g.pb(n/i);
			}
		}
	}
	if(n==1)
	{
		cout<<"1"<<endl;
		return 0;
	}
	if(g.size()==2)
	{
		cout<<n<<endl;
	}
	else
	{
		sort(g.begin(),g.end());
		ll h=g[1];
		while(n%h==0)
		{
			n/=h;
		}
		if(n==1)
		{
			cout<<h<<endl;
		}
		else
		{
			cout<<"1"<<endl;
		}
	}
}