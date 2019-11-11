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
		ll a,b,c;
		cin>>a>>b>>c;
		string x;
		cin>>x;
		ll cnt=0;
		string tmp=x;
		rep(i,0,x.length())
		{
			if(x[i]=='R')
			{
				if(b)
				{
					tmp[i]='P';
					b--;
					cnt++;
				}
				else
					tmp[i]='?';
			}
			if(x[i]=='P')
			{
				if(c)
				{
					tmp[i]='S';
					c--;
					cnt++;
				}
				else
					tmp[i]='?';
			}
			if(x[i]=='S')
			{
				if(a)
				{
					tmp[i]='R';
					a--;
					cnt++;
				}
				else
					tmp[i]='?';
			}
		}
		if(cnt>=(n+1)/2)
		{
			cout<<"YES\n";
			rep(i,0,tmp.length())
			{
				if(tmp[i]=='?')
				{
					if(a)
						{
							cout<<"R";
							a--;
						}
					else 
						if(b)
					{
						cout<<"P";
						b--;
					}
					else
						{
							cout<<"S";
							c--;
						}
				}
				else
					cout<<tmp[i];
			}
			cout<<endl;
		}
		else
		{
			cout<<"NO\n";
		}
	}
}