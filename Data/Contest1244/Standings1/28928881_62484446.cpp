#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18 + 7;
const int N = 1e5 + 10;
int n, k, a[N], sum[N], cnt[N];
int ans;

signed main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], cnt[i] = 1;
	sort(a + 1, a + n + 1);
	ans = a[n] - a[1];
	for (int i = 0; i < n; ++ i){
		int l = 1 + i;
		int r = n - i;
		if (l >= r) break;
		if (l + 1 != r){
			int can = k / (i+1);
			if (can == 0) break;
			int lim = a[l+1]-a[l] + a[r]-a[r-1];
			ans -= min(lim, can);
			k -= min(lim, can) * (i+1);
			if (lim > can) break;
		}
		if (l + 1 == r){
			int can = k / (i+1);
			if (can == 0) break;
			int lim = a[r]-a[l];
			ans -= min(lim, can);
			k -= min(lim, can) * (i+1);
		}
	}
	cout << ans << endl;
	return 0;
}