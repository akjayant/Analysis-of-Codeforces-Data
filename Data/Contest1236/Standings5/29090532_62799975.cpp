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
  int n;cin>>n;
  v ans[304];
  if(n&1)
  {
  	for(int i=0;i<n;i++)
  	{
  		ans[i].pb(n*n-i);
  	}
  	// n--;
 	 int l=1,f=n*n-n;
 	 int a=(n-1)/2;
  	int b=a;
  	for(int i=0;i<n;i++)
  	{	
  		for(int j=l;j<l+b;j++)
  			ans[i].pb(j);
  		for(int j=f;j>f-a;j--)
  			ans[i].pb(j);
  		l+=b;
  		f-=a;
  	// cout<<endl;
  	}
}
  else
  {
  	int l=1,f=n*n;
  int a=n-(n/2);
  int b=n/2;
  for(int i=0;i<n;i++)
  {
  	for(int j=l;j<l+b;j++)
  		ans[i].pb(j);
  	for(int j=f;j>f-a;j--)
  		ans[i].pb(j);
  	l+=b;
  	f-=a;

  }

  }
  for(int i=0;i<n;i++)
  {
  	for(auto it:ans[i])
  		cout<<it<<" ";
  	cout<<endl;
  }
  return 0;
  
}