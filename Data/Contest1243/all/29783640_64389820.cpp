#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define F first
#define S second
//cout<<fixed<<setprecision(11);
const string nl="\n";
const ll MOD=1000000007;
const ll ARR_MAX = 1e5+1;

ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

void solve(){
	ll n;cin>>n;
	ll x=0;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			x=gcd(x,i);
			x=gcd(x,n/i);
		}
	}
	if(x==0){
		cout<<n<<nl;
	}
	else{
		cout<<x<<nl;
	}
}

int main(){
    fastio();
    int t=1;
    // cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}