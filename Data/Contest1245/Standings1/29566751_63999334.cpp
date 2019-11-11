#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define endl "\n"
#define sz(x) ((ll)((x).size()))
const ll N=1e5+5,inf=1e18;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		ll a,b,c;
		cin >> a >> b >> c;
		string s;
		cin >> s;
		string t=s;
		ll cnt=n;
		lp(i,0,s.size())
		{
			t[i]='0';
			if(s[i]=='R'&&b>0)
			{
				t[i]='P';
				b--;
			}
			else if(s[i]=='P'&&c>0)
			{
				t[i]='S';
				c--;
			}
			else if(s[i]=='S'&&a>0)
			{
				t[i]='R';
				a--;
			}
			else
			{
				cnt--;
			}
		}
		lp(i,0,n)
		{
			if(t[i]=='0')
			{
				if(a>0)
				{
					t[i]='R';
					a--;
				}
				else if(b>0)
				{
					t[i]='P';
					b--;
				}
				else
				{
					t[i]='S';
					c--;
				}
			}
		}
		if(cnt>=(n+1)/2)
		{
			cout<<"YES"<<endl;
			cout<<t<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}	    
	return 0;
}