//katana_handler
//shakalaka_boom_boom
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define ordered_set_pll tree <pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree <ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//query 1 order_of_key (k) : Number of items strictly smaller than k .
//query 2 find_by_order(k) : K-th element in the set (counting from zero).
//less<ll> means query 1 will return numbers strictly less than k
//greater<ll> means query 1 will return numbers strictly greater than k
#define		pb                 push_back
#define		pf                push_front
#define		MOD             1000000007
#define		popb             pop_back
#define		popf            pop_front
#define		len(x)            x.size()    
#define		MAXN               100001
#define		mp                 make_pair
#define		endl             '\n'
#define		ff                 first
#define		ss                 second
#define		tt                third
#define		mapcl             map<char,ll>
#define		mapll             map<ll,ll>
#define		cmp             complex<double>
#define		pi                 3.141592653589793238462643383279502884197169399375105820974944592307816406286 
#define		inf             LLONG_MAX
#define		flush             fflush(stdout)
#define		vll             vector<ll>
#define		all(v)             v.begin(),v.end()
#define		fr(i,z,n)         for(ll i=z;i<n;i++)
#define		sqrt             sqrtl
#define		cbrt             cbrtl
typedef		long long        ll;
typedef		pair<ll,ll>        pll;
typedef		long double        ld;
bool		coll(pll p1,pll p2,pll p3)		{if((p3.ss-p2.ss)*(p2.ff-p1.ff)==(p2.ss-p1.ss)*(p3.ff-p2.ff))return true;else return false;}
void		print(auto x)					{cout<<x<<endl;}
void		pv(vector<auto> v)				{for(ll i=0;i<(ll)v.size();i++)cout<<v[i]<<" ";cout<<endl;}
void		pv1(vector<auto> v)				{for(ll i=1;i<(ll)v.size();i++)cout<<v[i]<<" ";cout<<endl;}
void		pset(set<auto> v)				{for(auto x:v)cout<<x<<" ";cout<<endl;}
void		pvsl(vector<auto> v)			{for(ll i=0;i<(ll)v.size();i++)cout<<v[i]<<" ";}
void		in(vector<auto> &v, ll n)		{v.resize(n);for(ll i=0;i<n;i++)cin>>v[i];}
void		in1(vector<auto> &v, ll n)		{v.resize(n+1);for(ll i=1;i<=n;i++)cin>>v[i];v[0]=0;}
void		sortv(auto &v)					{sort(v.begin(),v.end());}
void		fast()							{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
double		dist2d(pll a,pll b)				{ll x=abs(a.ff-b.ff);ll y=abs(a.ss-b.ss);return (sqrt((x*x)+(y*y)));}
int main()
{
	ll n,k;
	cin>>n>>k;
	ll ans=1e18;
	vll v;
	in(v,n);
	sortv(v);
	ans=v[n-1]-v[0];
	vector<ll> X,Y;
	ll sum=0;
	ll cnt=1;
	for(ll i=0;i<n;i++)
	{
		sum+=v[i];
		X.pb((v[i]*cnt++)-sum);
	}
	sum=0;
	cnt=1;
	for(ll i=n-1;i>=0;i--)
	{
		sum+=v[i];
		Y.pb(sum-(v[i]*cnt++));
	}
	//pv(X);
	reverse(all(Y));
	//pv(Y);
	for(ll i=0;i<n;i++)
	{
		if(X[i]+Y[i]<=k)
		{
			cout<<0<<endl;
			return 0;
		}
	}
	reverse(all(Y));
	for(ll i=0;i<n;i++)
	{
		ll x=X[i];
		if(i+1<n && X[i+1]==X[i])
		continue;
		if(x>k)
		break;
		ll y=k-x;
		auto it=upper_bound(all(Y),y);
		it--;
		ll ind=it-Y.begin();
		ind=n-ind-1;
		ll tot=x+*(it);
		ll rem=k-tot;
		ll left=i+1;
		ll right=n-ind;
		ll tans=abs(v[i]-v[ind]);
		ll vi,vind;
		vi=v[i];
		vind=v[ind];
		//cerr<<vi<<" "<<left<<"---"<<vind<<" "<<right<<endl;
		//cerr<<rem<<endl;
		ll diff=abs(vind-vi);
		ll take=min(min(diff,abs(v[i]-v[i+1])),(rem/left)+min(((rem%left)/right),abs(v[ind]-v[ind-1])));
		ll take1=min(min(diff,abs(v[ind]-v[ind-1])),(rem/right)+min(((rem%right)/left),abs(v[i]-v[i+1])));
		//cerr<<rem<<" "<<diff<<" "<<take<<" "<<take1<<endl;
		ans=min(ans,diff-max(take1,take));
	}
	swap(X,Y);
	reverse(all(v));
	for(ll i=0;i<n;i++)
	{
		ll x=X[i];
		if(i+1<n && X[i]==X[i+1])
		continue;
		if(x>k)
		break;
		ll y=k-x;
		auto it=upper_bound(all(Y),y);
		it--;
		ll ind=it-Y.begin();
		ind=n-ind-1;
		ll tot=x+*(it);
		//cout<<"here"<<tot<<endl;
		ll rem=k-tot;
		ll left=i+1;
		ll right=n-ind;
		ll tans=abs(v[i]-v[ind]);
		ll vi,vind;
		vi=v[i];
		vind=v[ind];
		//cerr<<vi<<" "<<vind<<endl;
		ll diff=abs(vind-vi);
		ll take=min(min(diff,abs(v[i]-v[i+1])),(rem/left)+min(((rem%left)/right),abs(v[ind]-v[ind-1])));
		ll take1=min(min(diff,abs(v[ind]-v[ind-1])),(rem/right)+min(((rem%right)/left),abs(v[i]-v[i+1])));
		ans=min(ans,diff-max(take1,take));
	}
	cout<<ans<<endl;
}
