#include <bits/stdc++.h>
#define MAXN 105
#define pii pair<int, int>
#define pb push_back
#define inf 1e18
#define fi first
#define se second
#define mt make_tuple
typedef long long ll;

using namespace std;

int n = 10, h[MAXN][MAXN], p[MAXN][MAXN];

double dp[MAXN];
vector<int> g[MAXN];

double go(int x){
	if(dp[x] > 0) return dp[x];
	if(x == 99) return 0;
	assert(x <= 99);
	int maxroll = min(6, 99 - x);
	for(int r = 1; r <= maxroll; r++){
		double t = go(x + r);
		if(g[x + r].size()) t = min(t, go(g[x + r][0]));
		t += 1;
		dp[x] += t / 6;
	}
	int stuck = 6 - maxroll;
	if(stuck > 0){
		dp[x] = 6.0 / maxroll * (dp[x] + stuck / 6.0);
	}
	return dp[x];
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 10; i++){
    	for(int j = 0; j < 10; j++){
    		cin >> h[i][j];
    	}
    }
    int c = 0;
    for(int i = 9; i >= 0; i--){
    	for(int j = 0; j < 10; j++){
    		if(i % 2) p[i][j] = c++;
    		else p[i][9 - j] = c++;
    	}
    }
    for(int i = 0; i < 10; i++){
    	for(int j = 0; j < 10; j++){
    		if(h[i][j] > 0){
    			g[p[i][j]].pb(p[i - h[i][j]][j]);
    		}
    	}
    }
    // for(int i = 0; i < 99; i++){
    // 	g[i].pb(i + 1);
    // }
    cout << fixed << setprecision(8) << go(0);
}