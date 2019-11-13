#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
	fast;
	ll k;
	cin>>k;
	while(k--){
		ll n;
		cin>>n;
		ll ar[n];
		for(ll i=0;i<n;i++)cin>>ar[i];
		sort(ar,ar+n);
		ll ans=0;
		for(ll i=0;i<n;i++){
			if(ar[i]>=n-i){
				ans=n-i;
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
