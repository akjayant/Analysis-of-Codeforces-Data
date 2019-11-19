#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,p,w,d;
	cin>>n>>p>>w>>d;
	for(ll i=0;i<=w;++i){
		ll tmp=p-i*d;
		if(tmp%w==0){
			ll x=tmp/w;
			if(x>=0&&x+i<=n){
				cout<<x<<' '<<i<<' '<<n-x-i<<'\n';
				return 0;
			}
		}
	}
	cout<<-1<<'\n';
	return 0;
}

