#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ll long long
#define dd double
#define MOD 1000000007
#define nl cout<<endl
#define rt ll Q[100005]={0}
#define mp make_pair
#define test() ull t;cin>>t;while(t--)
#define pb push_back
#define ff first	
#define ss second
#define all(v) v.begin(),v.end()
#define s(ar,n) sort(ar,ar+n)
#define rs(ar,n) sort(ar, ar+n, greater<ll>()) 
#define oa(a,n) for(ll i=0;i<n;i++)cout<<a[i]<<" ";nl
#define cn(a,n) for(ll i=0;i<n;i++)cin>>a[i];
#define ov(a,n) for(ll i=0;i<n;i++)cout<<a[i]<<" ";nl
#define maxa(ar,N) *max_element(ar,ar+N)
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
ll powe(ll n,ll m){if(m==0)return 1;ll t=powe(n,m/2);if(m%2==0)return (t*t);return (((t*t))*n);}
ll mpowe(ll n,ll m){if(m==0)return 1;ll t=powe(n,m/2);t%=MOD;if(m%2==0)return (t*t)%MOD;return (((t*t)%MOD)*n)%MOD;}
ll logtwo(ll n){if(n==1)return 0;return logtwo(n/2)+1;}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("outpu.txt", "w", stdout);
    #endif
    fastio();
    test()
    {
    	ll N;
    	cin>>N;
    	string s,t;
    	cin>>s>>t;
    	char sa,sb,ta,tb;
    	ll c=0;
    	for(ll i=0;i<N;i++)
    	{
    		if(s[i]!=t[i])
    			c++;
    	}
    	if(c!=2)
    		cout<<"No"<<endl;
    	else
    	{
    		c=0;
    		for(ll i=0;i<N;i++)
	    	{
	    		if(s[i]!=t[i])
	    		{
	    			if(c==0)
	    			{
	    				sa=s[i];
	    				ta=t[i];
	    				c++;
	    			}
	    			else
	    			{
	    				sb=s[i];
	    				tb=t[i];
	    			}
	    		}
	    	}
	    	if(sa==sb&&ta==tb)
	    		cout<<"Yes"<<endl;
	    	else
	    		cout<<"No"<<endl;
    	}
    }
	//cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
} 