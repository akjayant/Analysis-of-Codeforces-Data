#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int ll;

int main(){
	int n; cin >> n;
	ll k; cin >> k;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	ll sum=0;
	ll sum1=0;
	ll mid=n/2;
	for(int i=0;i<n;i++){
		sum+=abs(a[n/2]-a[i]);
		sum1+=abs(a[n/2-1]-a[i]);
	}
	if(min(sum,sum1)<=k){
		cout << 0 << endl;
		return 0;
	}
	ll ans=a[n-1]-a[0];
	ll now=0;
	ll bac=n-1;
	ll now1=0;
	while(k){
		for(int i=now;i<n;i++){
			ll cp=a[0];
			while(cp==a[i]){
				i++;
				now++;
			}
			break;
		}
		for(int i=bac;i>=0;i--){
			ll cp=a[n-1];
			while(cp==a[i]){
				i--;
				now1++;
				bac--;
			}
			break;
		}
		if(now<=now1){
			if((a[now]-a[0])*now<=k){
				k-=(a[now]-a[0])*now;
				ans-=(a[now]-a[0]);
				a[0]=a[now];
			}
			else{
				ans-=k/now;
				k=0;
			}
		}
		else{
			if((a[n-1]-a[bac])*now1<=k){
				k-=(a[n-1]-a[bac])*now1;
				ans-=(a[n-1]-a[bac]);
				a[n-1]=a[bac];
			}
			else{
				ans-=k/now1;
				k=0;
			}
		}
	}
	cout << ans << endl;
}