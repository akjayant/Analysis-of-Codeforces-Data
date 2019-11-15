#include<bits/stdc++.h>
 
#define hell                         1000000007
#define hell2                        998244353
#define lcm(a,b)                     (a*b)/__gcd(a,b)
#define ll                           long long
#define vll                          vector<ll>
#define vi                           vector<int>
#define pll                          vector< pair<ll,ll> >
#define pb                           push_back
#define mp                           make_pair
#define all(v)                       v.begin(),v.end()
#define lbnd                         lower_bound
#define ubnd                         upper_bound
#define bs                           binary_search
#define F                            first
#define S                            second
#define rep(i,a,b)                   for(ll i=a;i<b;i++)
#define parr(a,n)                    for(ll it=0;it<n;it++) cout<<a[it]<<" ";cout<<endl;
#define pcont(a)                     for(auto it:a) cout<<it<<" ";cout<<endl;
#define ret(x)                       return cout<<x,0;
#define endl                           '\n'
 
#define MAX 100005
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll t;
    cin >> t;
    while(t--) {
    	ll a,b,c;
    	cin >> a >> b >> c;
    	ll cnt=min(b,c/2);
    	ll ans=3*cnt;
    	b-=cnt;
    	c-=2*cnt;
    	cnt=min(a,b/2);
    	cout << ans+3*cnt << endl;
    }
}