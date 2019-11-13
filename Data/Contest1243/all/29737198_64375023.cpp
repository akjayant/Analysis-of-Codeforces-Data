#include<bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin(),(v).end()
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define sz(a) (ll)(a.size())
#define mod 1000000007
#define fi first
#define se second
#define pii pair<ll,ll>

using namespace std;

int main(){
	ll t,i,j,k,m,n;
	t=1;
	cin>>t;
	while(t--){
		cin>>n;
		ll ar[n];
		for(i=0;i<n;i++){
			cin>>ar[i];
		}
		sort(ar,ar+n);
		ll ans=1;
		ll c=1;
		for(i=n-1;i>=0;i--){
			ll x=ar[i];
			ans=max(ans,min(x,c));
			c++;
		}
		cout<<ans<<"\n";

	}
	return 0;
}