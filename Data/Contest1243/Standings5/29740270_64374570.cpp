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

ll power(ll a,ll b)
{
	a=a%mod;
	ll ans=1;
	while(b>0)
	{
		if(b%2==1)
		{
			ans=(ans*a)%mod;
		}
		b=b/2;
		a=(a*a)%mod;
	}
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		ll ans=0;
		for(ll i=0;i<n;i++)
		{
			ans=max(ans,min(a[i],n-i));
		}
		cout<<ans<<endl;
	}
    
}
