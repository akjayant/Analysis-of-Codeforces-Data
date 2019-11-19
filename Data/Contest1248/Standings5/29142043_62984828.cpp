#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
ll sum[100005];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
	ll ans=0;
	ans=sum[n/2]*sum[n/2]+(sum[n]-sum[n/2])*(sum[n]-sum[n/2]);
	cout << ans;
	return 0;
}