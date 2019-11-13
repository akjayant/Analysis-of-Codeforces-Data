#include <bits/stdc++.h>
#include <iomanip>
#include <typeinfo>
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define	endl		'\n'
#define mii         map<ll int,ll int>
#define msi         map<string,ll int>
#define mis         map<ll int, string>
#define mpi         map<pair<ll int,ll int>,ll int>
#define mip         map<ll int,pair<ll int,ll int> >
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define MAXN   	    1000000007
#define rep(i,a,b)  for (long long int i=a;i<b;i++)
#define repr(i,a,b) for (long long int i=a-1;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ios         ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
using namespace std;
 
bool cmp(const pii &a,const pii &b) { 
    return a.second>b.second;
}
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
void solve() {
    ll n,m;
    cin>>n>>m;
    ll base=2;
    ll res1=power(2,m,MAXN);
    res1--;
    res1%=MAXN;
    cout<<power(res1,n,MAXN);
}
 
signed main() {
    ios
    ll test=1;
    //Scout<<1;
    //freopen("input.txt","r",stdin);
    //cin>>test;
    while (test--) solve();
    return 0;
}