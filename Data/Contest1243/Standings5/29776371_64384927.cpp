/* ****TCIITB**** */

#include<bits/stdc++.h>
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

#define N  100005

int main()
{
	
	io

	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		string x;
		cin>>x;
		string y;
		cin>>y;
		ll res=0;
		std::vector<ll> pos;
		rep(i,0,n)
		{
			if(x[i]!=y[i])
				{
					pos.pb(i);
				}
		}
		if(pos.size()==2 || pos.size()==0)
		{
			if(x[pos[0]]==x[pos[1]] && y[pos[0]]==y[pos[1]])
				cout<<"YES\n";
			else
				cout<<"NO\n";			
		}
		else
		{
			cout<<"NO\n";	
		}
	}
	
}