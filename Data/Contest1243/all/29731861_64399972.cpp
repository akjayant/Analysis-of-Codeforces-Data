#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

pll f(ll n){
	ll mx = 0,cnt = 0;
	for(ll i = 2;i*i <=n;i++){
		if(n%i==0){
			while(n%i==0)n = n/i;
			cnt ++;
			if(mx==0)mx = i;
		}
	}
	if(n!=1){
		cnt++;
		if(mx==0)mx = n;
	}
	return make_pair(mx,cnt);
}

int main(){
	ll n; cin>>n;
	pll ans = f(n);
	if((ans.second >= 2) || n==1){
		cout<<1<<"\n";
		return 0;
	}
	cout<<ans.first<<"\n";
	return 0;
}
