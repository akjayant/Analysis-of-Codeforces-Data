#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <assert.h>
#include <queue>
#include <deque>
using namespace std;
#define LL long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int n;
vector < int > E[100005];
LL cost[3][100005];
LL dp[3][3][100005];
int color[100005];

LL f( int u , int p, int c1, int c2 ){
	LL &ans = dp[c1][c2][u];
	if ( ans != -1 ) return ans;
	ans = 1e18;
	int child = 0;
	for ( int e : E[u] ){
		if ( e == p ) continue;
		child++;
		for ( int c = 0; c < 3; c++ ){
			if ( c == c1 || c == c2 ) continue;
			ans = min( ans, f(e,u,c2,c) + cost[c][e]);
		}
	}
	if ( child == 0 ) ans = 0;
	return ans;
}

void dfs( int u , int p, int c1, int c2 ){
	color[u] = c2 + 1;
	for ( int e : E[u] ){
		if ( e == p ) continue;
		for ( int c = 0; c < 3; c++ ){
			if ( c == c1 || c == c2 ){
				continue;	
			}
			if ( f(e,u,c2,c) + cost[c][e] == f(u,p,c1,c2) ){
				dfs(e,u,c2,c);
			}
		}
	}
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc = 1;
	// cin >> tc;
	while ( tc-- ){
		memset(dp,-1,sizeof(dp));
		cin >> n;
		for ( int i = 0; i < 3; i++ ){
			for ( int j = 1; j <= n; j++ ) cin >> cost[i][j];
		}
		for ( int i = 0; i < n-1; i++ ){
			int u , v;
			cin >> u >> v;
			E[u].pb(v);
			E[v].pb(u);
		}
		LL ans = -1;
		for ( int i = 1; i <= n; i++ ){
			if (E[i].size() > 2 ) {
				ans = 1e18;
				break;
			}
		}

		if ( ans == -1 ){
			ans = 1e18;
			for ( int i = 1; i <= n; i++ ){
				if ( E[i].size() == 1 ){
					for ( int j = 0; j < 3; j++ ){
						ans = min( ans, f(i,-1,j,j) + cost[j][i]);
					}
					cout << ans << endl;
					for ( int j = 0; j < 3; j++ ){
						if ( f(i,-1,j,j) + cost[j][i] == ans ){
							dfs(i,-1,j,j);
							break;
						}
					}
					for ( int u = 1; u <= n; u++ ) {
						cout << color[u];
						if ( u < n ) cout << " ";
					}
					cout << endl;
					break;
				}
			}
		}

		if ( ans == 1e18 ) cout << -1 << endl;
	}
	return 0;
}