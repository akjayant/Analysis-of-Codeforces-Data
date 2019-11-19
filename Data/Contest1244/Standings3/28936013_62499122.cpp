#include <bits/stdc++.h>
 
#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define all(s) s.begin(),s.end()
#define int long long
 
using namespace std;
 
const int N = (1e5 + 12);
const int mod = (1e9 + 7);
const int INF = (0x3f3f3f3f);
 
int c[4][N], dp[8][N], cur;
vector<int > g[N];
vector<int > vec;
int ans[N];
bool f = true;
void dfs(int v,int pr)
{
	if(g[v].size() >= 3){
		cout << -1;
		exit(0);
	}
	for(auto to : g[v]){
		if(to != pr){
			dfs(to, v);
		}
	}
	if(f){
		cur = v;
		f = false;
	}
}
void dfs1(int v,int pr){
	for(auto to : g[v]){
		if(to != pr){
			dfs1(to, v);
		}
	}
	vec.pb(v);
}
main()
{	
	int n;
	cin >> n;
	for(int i = 1;i <= 3; i++){
		for(int j = 1;j <= n; j++){
			scanf("%lld", &c[i][j]);
		}
	}
	int u, v;
	for(int i = 1;i <= n - 1; i++){
		scanf("%lld%lld", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,-1);
	dfs1(cur, -1);
	dp[1][vec[1]] = c[1][vec[1]] + c[2][vec[0]];
	dp[2][vec[1]] = c[1][vec[1]] + c[3][vec[0]];
	dp[3][vec[1]] = c[2][vec[1]] + c[1][vec[0]];
	dp[4][vec[1]] = c[2][vec[1]] + c[3][vec[0]];
	dp[5][vec[1]] = c[3][vec[1]] + c[1][vec[0]];
	dp[6][vec[1]] = c[3][vec[1]] + c[2][vec[0]];
	for(int i = 2;i < vec.size(); i++){
		int to = vec[i], to1 = vec[i - 1];
		dp[1][to] = dp[4][to1] + c[1][to];
		dp[2][to] = dp[6][to1] + c[1][to];
		dp[3][to] = dp[2][to1] + c[2][to];
		dp[4][to] = dp[5][to1] + c[2][to];
		dp[5][to] = dp[1][to1] + c[3][to];
		dp[6][to] = dp[3][to1] + c[3][to];
	}
	int to = vec[vec.size() - 1], x;
	x = min({dp[1][to],dp[2][to],dp[3][to],dp[4][to],dp[5][to],dp[6][to]});
	int w, w1;
	if(x == dp[1][to]){
		w = 1;
		w1 = 2;
	}
	if(x == dp[2][to]){
		w = 1;
		w1 = 3;
	}
	if(x == dp[3][to]){
		w = 2;
		w1 = 1;
	}
	if(x == dp[4][to]){
		w = 2;
		w1 = 3;
	}
	if(x == dp[5][to]){
		w = 3;
		w1 = 1;
	}
	if(x == dp[6][to]){
		w = 3;
		w1 = 2;
	}
	cout << x << endl;
	for(int i = vec.size() - 1;i >= 1; i--){
		//cout << w << " " << w1 << endl;
		ans[vec[i]] = w;
		if(w == 1 && w1 == 2){
			w1 = 3;
			w = 2;
		}
		else
		if(w == 1 && w1 == 3){
			w1 = 2;
			w = 3;
		}
		else
		if(w == 2 && w1 == 1){
			w1 = 3;
			w = 1;
		}
		else
		if(w == 2 && w1 == 3){
			w1 = 1;
			w = 3;
		}
		else
		if(w == 3 && w1 == 1){
			w1 = 2;
			w = 1;
		}
		else
		if(w == 3 && w1 == 2){
			w1 = 1;
			w = 2;
		}
	}
	ans[vec[0]] = w;
	for(int i = 1;i <= n; i++){
		cout << ans[i] << " ";
	}
}
