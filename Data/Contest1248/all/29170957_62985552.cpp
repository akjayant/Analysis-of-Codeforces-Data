#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100000 + 10;
int n,a[maxn],ans,ans2;
signed main() {
	scanf("%lld",&n);
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++) {
		if (i <= (n&1 ? n-1>>1 : n/2)) ans2 += a[i];
		else ans += a[i];
	}
	printf("%lld",ans*ans+ans2*ans2);
	return 0;
}