#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1e3+5;
typedef long long ll;
ll a[maxn],n,k;
bool chk(ll x){
	ll lef=0;
	ll cnt=0;
	for (int i=n;i>=1;i--){
		if (a[i]>=x) cnt++;
	}
	if (cnt>=x) return true;
	return false;
}
int main(){
	cin>>k;
	while(k--){
		scanf("%lld",&n);
		for (int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+n+1);
		ll l=0,r=1e9,ans=0;
		while(l<=r){
			ll mid=(l+r)/2;
			if (chk(mid)){
				l=mid+1;
				ans=mid;
			}
			else r=mid-1;
		}
		cout<<ans<<endl;
	}
}