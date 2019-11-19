#include <bits/stdc++.h>

using namespace std;
const int N=1e5+10;
typedef long long ll;

int n;
ll a[N];

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	ll ans1=0, ans2=0;
	for(int i=1; i<=n/2; i++) {
		ans1+=a[i];	
	}
	for(int i=n/2+1; i<=n; i++) {
		ans2+=a[i];
	}
	cout<<ans1*ans1+ans2*ans2<<endl;
	return 0;
}
