#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5+5;
#define line; printf("========\n");
#define endl '\n'
ll a[maxn], b[maxn], c[maxn];
ll num[maxn], vis[maxn], res, ans;
ll color[maxn];
vector<ll> edge[maxn];
ll n;
ll f, e;
void dfs(int x, int y, int z) {
//	printf("%d %d %d\n", x, y, z);
	vis[z] = x;
	if(x == 1)
	res += a[z];
	else if(x == 2)
	res += b[z];
	else 
	res += c[z];
	int dd;
	if(x+y == 3) {
		dd = 3;
	} else if(x+y == 4) {
		dd = 2;
	} else {
		dd = 1;
	}
	if(vis[edge[z][0]] == 0) {
		dfs(y, dd,edge[z][0]);
	} else if(edge[z].size() > 1 && vis[edge[z][1]] == 0){
		dfs(y, dd,edge[z][1]);
	}
}
void solve(int a, int b) {
	for(ll i = 0; i <= n; i++) {
		vis[i] = 0;
	}
	res = 0;
	dfs(a, b, f);
//	printf("%d %d %d\n", res, a,b);
	if(ans > res) {
		for(int i = 1; i <= n; i++) {
			color[i] = vis[i];
		}
		ans = res;
	}
}
int main() {
	std::ios::sync_with_stdio(false);

	cin>>n;
	for(ll i = 1; i <= n; i++) {
		cin>>a[i];
		//printf("%lld\n", a[i]);
	}
	for(ll i = 1; i <= n; i++) {
		cin>>b[i];
	//	printf("%lld\n", b[i]);
	}
	for(ll i = 1; i <= n; i++) {
		cin>>c[i];
	//	printf("%lld\n", c[i]);
	}
	ll x, y;
	for(ll i = 0; i < n-1; i++) {
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
		num[x]++;
		num[y]++;
	}
	f = -1, e = -1;
	for(ll i = 1; i <= n; i++) {
//		cout<<i<<" ";
		if(num[i] > 2) {
			cout<<"-1"<<endl;
			return 0;
		}
		if(f == -1 && num[i] == 1) {
			f = i;
		}
		if(f != -1 &&num[i] == 1) {
			e = i;
		}
	}
	ans = 1000000000000000LL;
//	printf("%lld\n", ans);
	solve(1,2);
//	line;
	solve(1,3);
	solve(2,1);
	solve(2,3);
	solve(3,1);
	solve(3,2);
	cout<<ans<<endl;
	for(int i = 1; i <= n; i++){
		cout<<color[i]<<" ";
	}


	return 0;
}