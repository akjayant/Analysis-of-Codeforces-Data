#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long  i = 0; i < (n); ++i)
#define repA(i, a, n) for(long long i = a; i <= (n); ++i)
#define repD(i, a, n) for(long long i = a; i >= (n); --i)
#define travMap(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define INF 1e9
#define mod 1000000007
#define ok(i,s) i<s.size()
const long double PI = 3.141592653589793238462643383;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<long long int> vi;
typedef vector<vector<long long int> > vii;
typedef vector<pii > vp;
 
ll Gcd(ll a, ll b) 
{ 
    if (!a) 
       return b; 
    return Gcd(b%a,a); 
} 
 
 
ll maxx(ll a,ll b){
    if(a>b)
        return a;
    return b;
}
ll minn(ll a,ll b){
    return a+b-maxx(a,b);
}
 
 
ll Ceil(ll a,ll b){
    if(a%b==0)
        return a/b;
    return a/b +(a*b<0?0:1);
 
}
 
ll Floor(ll a, ll b){
    return a/b-(a*b<0?1:0);
}
 
ll abso(ll a){
	if(a>0)
		return a;
	return -a;
}
 

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	ll a_even = 0,a_odd = 0;
    	rep(i,n){
    		ll x;
    		cin>>x;
    		if(x%2==0)
    			a_even++;
    		else
    			a_odd++;
    	}
    	ll b_even = 0,b_odd = 0;
    	ll m;
    	cin>>m;
    	rep(i,m){
    		ll x;
    		cin>>x;
    		if(x%2==0)
    			b_even++;
    		else
    			b_odd++;
    	}
    	ll ans = a_even*b_even+a_odd*b_odd;
    	cout<<ans<<"\n";
    }
}