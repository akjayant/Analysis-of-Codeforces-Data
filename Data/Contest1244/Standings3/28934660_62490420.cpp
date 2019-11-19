#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cassert>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<deque>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string.h>
#include<string>
#include<iomanip>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FOR(i,k,n) for(int i = k ; i < n ; ++i)
#define REP(i,k,n) for(int i = k ; i <= n ; ++i)
#define sz(x) (int)x.size()
#define VAR(x) #x << " " << x
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;

static const int N = 1e5 + 4;;

ll dp[N][3][3], cost[N][3];
vector<int> G[N];
ll color[N];

void dfs(int v, int f) {
	for (auto u : G[v]) {
		if (u != f) {
			dfs(u, v);
			dp[v][0][1] = dp[u][1][2] + cost[v][0];
			dp[v][0][2] = dp[u][2][1] + cost[v][0];
			dp[v][1][0] = dp[u][0][2] + cost[v][1];
			dp[v][1][2] = dp[u][2][0] + cost[v][1];
			dp[v][2][1] = dp[u][1][0] + cost[v][2];
			dp[v][2][0] = dp[u][0][1] + cost[v][2];
		}
	}
	if (v != f && sz(G[v]) == 1) {
		dp[v][0][1] = cost[v][0];
		dp[v][0][2] = cost[v][0];
		dp[v][1][2] = cost[v][1];
		dp[v][1][0] = cost[v][1];
		dp[v][2][1] = cost[v][2];
		dp[v][2][0] = cost[v][2];
	}
}

void kolor(int v, int f, int c, int c2) {
	color[v] = c;
	for (auto u : G[v]) {
		if (u != f) {
			if (c == 0 && c2 == 1) c2 = 2;
			else if (c == 2 && c2 == 1) c2 = 0;
			else if (c == 1 && c2 == 0) c2 = 2;
			else if (c == 2 && c2 == 0) c2 = 1;
			else if (c == 0 && c2 == 2) c2 = 1;
			else if (c == 1 && c2 == 2) c2 = 0;
			kolor(u, v, c2, c);
		}
	}
}

int main() {
	boost;
	int n;
	cin >> n;
	for (int i = 1 ; i<= n ; ++i) cin >> cost[i][0];
	for (int i = 1 ; i<= n ; ++i) cin >> cost[i][1];
	for (int i = 1 ; i<= n ; ++i) cin >> cost[i][2];
	for (int i = 0; i <n-1; ++i) {
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
		if (sz(G[a]) > 2 || sz(G[b]) > 2) {
			cout << "-1\n";
			return 0;
		}
	}

	int s = 0;
	for (int i = 1 ; i<= n ;++i) if(sz(G[i]) == 1) s = i;

	dfs(s,s);
	ll ans = min(min(min(dp[s][0][1], dp[s][1][0]), min(dp[s][0][2], dp[s][2][0])), min(dp[s][1][2], dp[s][2][1]));
	int c = -1;
	int v = G[s].back();

	if (dp[s][0][1] == ans || dp[s][0][2] == ans) {
		color[s] = 0;
		if (dp[v][1][2] < dp[v][2][1])
			c = 1;
		else c = 2;
	}
	else if (dp[s][1][0] == ans || dp[s][1][2] == ans) {
		color[s] = 1;
		if (dp[v][2][0] < dp[v][0][2])
			c = 2;
		else c = 0;
	}
	else if (dp[s][2][0] == ans || dp[s][2][1] == ans) {
		color[s] = 2;
		if (dp[v][0][1] < dp[v][1][0])
			c = 0;
		else c = 1;
	}

	cout << ans << "\n";
	kolor(v, s, c, color[s]);
	for (int i = 1 ; i <= n ; ++i) cout << color[i] + 1 << " ";
	cout << "\n";
}