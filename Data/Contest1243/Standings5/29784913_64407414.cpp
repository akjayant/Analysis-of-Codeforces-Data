
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
    	ll ar[26]={};
    	for(ll i=0;i<N;i++)
    	{
    		ar[s[i]-'a']++;
    		ar[t[i]-'a']++;
    	}
    	ll f=0;
    	for(ll i=0;i<26;i++)
    		if(ar[i]%2!=0)
    			f=1;
    	if(f==1)
    		cout<<"No"<<endl;
    	else
    	{
    		cout<<"Yes"<<endl;
    		vector <ll> v[2];
    		for(ll i=0;i<N-1;i++)
    		{
    			if(s[i]!=t[i])
    			{
    				//cout<<s[i]<<endl;
    				for(ll j=i+1;j<N;j++)
    				{
    					if(s[j]==s[i])
    					{
    						v[0].pb(j+1);
    						v[1].pb(i+1);
    						swap(s[j],t[i]);
    						f=1;
    						break;
    					}
    				}
    				if(f!=1)
    				{
    					for(ll j=i+1;j<N;j++)
    					{
    						//cout<<s[i]<<endl;
    						if(t[j]-s[i]==0)
    						{
    							v[0].pb(i+2);
	    						v[1].pb(j+1);
	    						swap(s[i+1],t[j]);
	    						v[0].pb(i+2);
	    						v[1].pb(i+1);
	    						swap(s[i+1],t[i]);
	    						f=1;
	    						break;
    						}
    					}
    				}
    				f=0;
    			}
    		}
    		//cout<<s<<" "<<t<<endl;
    		cout<<v[0].size()<<endl;
    		for(ll i=0;i<v[0].size();i++)
    		{
    			cout<<v[0][i]<<" "<<v[1][i]<<endl;
    		}
    	}
    }
	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
} 