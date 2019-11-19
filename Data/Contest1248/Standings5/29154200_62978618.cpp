#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll T;
	cin>>T;
	while(T--){
		ll n,m;
		ll a1=0,a2=0;
		cin>>n;
		for(ll i=1;i<=n;++i){
			ll x;
			cin>>x;
			if(x&1) ++a1;
			else ++a2;
		}
		cin>>m;
		ll ans=0;
		for(ll i=1;i<=m;++i){
			ll x;
			cin>>x;
			if(x&1) ans+=a1;
			else ans+=a2;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
