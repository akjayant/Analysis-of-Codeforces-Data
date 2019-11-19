/*input
5
3 4 2 1 2
4 2 1 5 4
5 3 2 1 1
1 2
3 2
4 3
5 3

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int const N = 1e5 + 10;
int a[N][3];
vector<int> v[N];
int dp[N][3][3];
const int inf = 1e18;
vector<int> b;
void dfs(int i,int p = -1){
	b.pb(i);
	for(auto x : v[i]){
		if(x == p)continue;
		dfs(x,i);
	}
}
signed main() {
	IOS;
	int n, x, y;
	cin >> n;
	for(int j = 0 ; j < 3 ; j++){
		for(int i = 1; i <= n ; i++){
			cin >> a[i][j];
		}
	}
	for(int i = 0 ; i < n - 1 ; i++)
	{	
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	int root = -1;
	for(int i = 1 ;i <= n ; i++){
		if(v[i].size() >= 3){
			return cout << -1 << endl,0;
		}
		if(v[i].size() == 1)root = i;
	}
	dfs(root);
	int ans = inf;
	vector<int> c = {0,1,2};
	do{
		int cur = 0;
		for(int i = 0 ; i < n ; i++){
			cur += a[b[i]][c[i%3]];
		}
		ans = min(ans,cur);
	}
	while(next_permutation(c.begin(), c.end()));
	vector<int> res(n+1,0);
	do{
		int cur = 0;
		for(int i = 0 ; i < n ; i++){
			cur += a[b[i]][c[i%3]];
		}
		if(cur == ans){
			cout << ans << endl;
			for(int i = 0 ; i < n ; i++){
				res[b[i]] = c[(i%3)]+1;
			}
			for(int i = 1; i <= n; i++){
				cout << res[i] << " ";
			}
			return 0;
		}
	}
	while(next_permutation(c.begin(), c.end()));

	
return 0;
}
