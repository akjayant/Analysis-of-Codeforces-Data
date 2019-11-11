#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl "\n"
#define ui unsigned int
#define lu unsigned long long
#define mod 1000000007
#define ld long double
#define f(i, n) for(ll i = 0; i < n; i++)
#define ff(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define v vector<ll>
#define vv vector<vector<ll> >
#define vs vector<string>
#define vpr vector<pair<ll,ll>>
#define fi first
#define se second
#define all(x)  x.begin(),x.end()
#define bg(x)  x.begin()
#define sz(x)  x.size()
#define in(x,n) f(i,n) cin>>x[i]
#define out(x,n) f(i,n) cout<<x[i]<<" "
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define mxt(a) *(max_element(a.begin(),a.end()))
#define mnt(a)  *(min_element(a.begin(),a.end()))
#define mem(x,val) memset(x,val,sizeof(x))
#define tc    ll t;cin>>t;while(t--)
#define prfloat(val,precise) cout<<fixed<<setprecision(precise)<<val<<endl;
const ld PI = 2 * acos(0.0);
void yes(){ cout<<"YES\n";}
void no(){cout<<"NO\n";cout<<-1<<"\n";exit(0);}
ll m(ll a){ return (a+mod)%mod;}
ll cel(ll x1,ll y1){ ;if((x1%y1)==0)return x1/y1;return x1/y1+1;}
ll power(ll a,ll b){ if(b==0)return 1;ll d=power(a,b/2);d=m(d*d);
if(b&1)d=m(d*a);return d;}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  tc{
  	int n;cin>>n;
  	int a,b,c;cin>>a>>b>>c;
  	string str;cin>>str;
  	string ans=str;
  	int c1=0;
  	for(int i=0;i<n;i++)
  		ans[i]='A';
  	for(int i=0;i<n;i++)
  	{
  		if(str[i]=='R')
  		{
  			if(b!=0)
  			{
  				ans[i]='P';
  				c1++;
  				b--;
  			}
  		}
  		if(str[i]=='P')
  		{
  			if(c!=0)
  			{
  				ans[i]='S';
  				c--;
  				c1++;
  			}

  		}
  		if(str[i]=='S')
  		{
  			if(a!=0)
  			{
  				ans[i]='R';
  				c1++;
  				a--;
  			}
  		}
  	}
  	int d=n/2;
  	if(n&1)
  		d++;
  	if(c1 >=d)
  	{
  		cout<<"YES\n";
  		for(int i=0;i<n;i++)
  		{
  			if(ans[i]=='A')
  			{
  				if(a!=0)
  				{
  					ans[i]='R';
  					a--;
  				}
  				else if(b!=0)
  				{
  					ans[i]='P';
  					b--;
  				}
  				else
  				{
  					ans[i]='S';
  					c--;
  				}
  			}
  		}
  		cout<<ans<<endl;
  	}
  	else
  	{
  		cout<<"NO\n";
  		continue;
  	}
  }
  
}