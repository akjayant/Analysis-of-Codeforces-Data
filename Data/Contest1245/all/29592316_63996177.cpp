// Do you knOW what it feels like?
 
		// To be TorTured by your own MinD?
	
	// I don't wanna feel the PAIN.
 
// I BeG you to KILL me, pleASE...
 
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define SZ(x) (long long)(x.size())
#define all(x) x.begin(),x.end()
 
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;

const ll maxn=1e5+10, LG=18, mod=1e9+7, inf=1e18;



int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	ll T; cin>>T;
	while(T--){
		ll a,b; cin>>a>>b;
		cout<<(__gcd(a,b)==1 ? "Finite":"Infinite")<<endl;
	}

	return 0;
}































