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
	 string s;
	 cin>>s;
	 string h;
	 cin>>h;
	 ll f=0;
	 char a,b;
	 ll g=0;
	 for(ll i=0;i<n;i++)
	 {
	 	if(s[i]!=h[i])
	 	{
	 		if(f==0)
	 		{
	 		a=s[i];
	 		b=h[i];
	 		f=1;
	 	    }
	 	    else if(f==1)
	 	    {
	 	    	if(s[i]!=a || h[i]!=b)
	 	    	{
	 	    		g=1;
	 	    		break;
				}
				f=2;
			}
			else
			{
				g=1;
				break;
			}
		}
	 }
	 if(g==1 || f==1)
	 {
	 	cout<<"No"<<endl;
	 }
	 else
	 {
	 	cout<<"Yes"<<endl;
	 }
	}
    
}
