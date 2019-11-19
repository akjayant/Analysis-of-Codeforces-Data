#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 2000+5;

int n, x[N], y[N], u[N], v[N], vis[N], kp[N], tot, k[N], c;
ll dist[N], mp[N][N];
int ans[N], cnt;

ll Prim() {
    ll ans = 0;
    for (int i = 1; i <= n; i++) dist[i] = mp[1][i], kp[i] = 1;
    vis[1] = 1;
    for (int t = 1; t < n; t++) {
        int loc; ll minn = 1e18;
        for (int i = 1; i <= n; i++)
			if (!vis[i] && dist[i] < minn)
            	minn = dist[i], loc = i;
        ans += minn; vis[loc] = 1; u[++tot] = loc, v[tot] = kp[loc];
        for (int i = 1; i <= n; i++)
        	if (dist[i] > mp[loc][i])
				dist[i] = mp[loc][i], kp[i] = loc;
    }
    for (int i = 1; i <= tot; i++)
    	if (u[i] > v[i]) swap(u[i], v[i]);
    return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c);
		mp[1][i+1] = mp[i+1][1] = c;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &k[i]);
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			mp[i+1][j+1] = mp[j+1][i+1] = 1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
	++n;
	printf("%I64d\n", Prim());
	for (int i = 1; i <= tot; i++)
		if (u[i] == 1) ans[++cnt] = v[i]-1;
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
		printf("%d%c", ans[i], " \n"[i == cnt]);
	printf("%d\n", tot-cnt);
	for (int i = 1; i <= tot; i++)
		if (u[i] != 1)
			printf("%d %d\n", u[i]-1, v[i]-1);
	return 0;
}
