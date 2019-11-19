#pragma GCC optimize ("-O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
ll NUM = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define zer ll(0)

ll n,k;
v64 nums;
v64 pref;

bool fn(ll diff)
{
	ll minm = INF;
	forn(i, n)
	{
		// cout<<i<<'\n';
		ll s1 = pref[i+1];
		// cout<<s1<<'\n';
		ll rval = nums[i]+diff;
		// cout<<rval<<'\n';
		ll pos = lower_bound(nums.begin(), nums.end(), rval)-nums.begin();
		// cout<<pos<<'\n';
		ll s2 = pref[n]-pref[pos];
		// cout<<s2<<'\n';
		ll tmp = nums[i]*(i+1) - s1;
		// cout<<tmp<<'\n';
		tmp += s2 - (n-pos)*rval;
		// cout<<tmp<<'\n';
		minm = min(tmp, minm);
		// cout<<minm<<'\n';
		// cout<<"ends\n";
	}
	forn(i, n)
	{
		ll s2 = pref[n]-pref[i];
		ll rval = nums[i];
		ll lval = nums[i]-diff;
		ll pos = lower_bound(nums.begin(), nums.end(), lval)-nums.begin();
		ll s1 = pref[pos];
		ll tmp = lval*(pos) - s1;
		tmp += s2 - (n-i)*rval;
		minm = min(tmp, minm);
	}
	if(minm <= k)
	{
		return 1;
	}
	return 0;
}

int main()
{
    fast_cin();
    cin>>n>>k;
    ll tmp;
    forn(i, n)
    {
    	cin>>tmp;
    	nums.pb(tmp);
    }
    sort(nums.begin(), nums.end());
    ll l = 0;
    ll r = nums[n-1]-nums[0];
    pref.pb(0);
    forn(i, n)
    {
    	pref.pb(pref[i]+nums[i]);
    }
    while(r-l > 1)
    {
    	ll diff = (l+r)/2;
    	if(fn(diff))
    	{
    		r = diff;
    	}
    	else
    	{
    		l = diff;
    	}
    }
     ll ans;
     if(fn(l))
     {
     	ans = l;
     }
     else
     {
     	ans = r;
     }
    cout<<ans<<'\n';
    return 0;
}
