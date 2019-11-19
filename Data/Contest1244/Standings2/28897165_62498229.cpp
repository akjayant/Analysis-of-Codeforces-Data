#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
ll a[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	ll l=1,r=n;
	sort(a+1,a+n+1);
	ll mx=a[n],mn=a[1];
	while(k){
//		cout<<mn<<' '<<mx<<' '<<k<<'\n';
		if(mx==mn) break;
		if(l<=(n-r+1)){
			if(k<l) break;
			ll tmp=min(k/l,(a[l+1]-mn));
			k-=tmp*l;
			mn+=tmp;
			while(mn==a[l+1]) ++l;
		}
		else{
			if(k<(n-r+1)) break;
			ll tmp=min(k/(n-r+1),(mx-a[r-1]));
			k-=tmp*(n-r+1);
			mx-=tmp;
			while(mx==a[r-1]) --r; 
		}
	}
	cout<<mx-mn<<'\n';
	return 0;
}

