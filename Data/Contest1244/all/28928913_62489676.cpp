#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int Maxn = 1e5+10;
int a[Maxn], head[Maxn], n, d[Maxn], g[2*Maxn], nxt[2*Maxn], cnt;
void addedge(int x, int y){
	cnt++; g[cnt] = y, nxt[cnt] = head[x], head[x] = cnt;
}
long long dp[Maxn][6][6], c[6][Maxn];
pii to[Maxn][6][6];
void dfs(int x, int fa){
	a[++cnt] = x;
	for(int i = head[x]; i; i = nxt[i]){
		if(g[i] != fa){
			dfs(g[i], x);
		}
	}
}
int Ans[Maxn];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &c[1][i]);
	for(int i = 1; i <= n; i++) scanf("%d", &c[2][i]);
	for(int i = 1; i <= n; i++) scanf("%d", &c[3][i]);
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		addedge(x, y); addedge(y, x);
		d[x]++, d[y]++;
	}
	for(int i = 1; i <= n; i++){
		if(d[i] >= 3) {
			printf("-1");
			return 0;
		}
	}
	cnt = 0;
	for(int i = 1; i <= n; i++){
		if(d[i] == 1){
			dfs(i, 0);
			break;
		}
	}
	long long ans = 1e18;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			for(int k = 1; k <= 3; k++){
				dp[i][j][k] = 1e18;
			}
		}
	}
	pii u;
	//dp[1][1] = c[1][1], dp[1][2] = c[1][2], dp[1][3] = c[1][3];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 3; j++){
			for(int k = 1; k <= 3; k++){
				for(int z = 1; z <= 3; z++){
					if(j != k && j != z && k != z){
					if(dp[i-1][k][z] + c[j][a[i]] < dp[i][j][k]){
						dp[i][j][k] = min(dp[i-1][k][z] + c[j][a[i]] , dp[i][j][k]);
						to[i][j][k] = pii(k, z); 
					}
						if(i == n){
							if(dp[i][j][k] < ans){
								u = pii(j, k);
								ans = min(ans, dp[i][j][k]);
							}
						}
					}
				}
			}
		}
	cout<<ans<<endl;
	for(int i = n; i >= 1; i--){
		Ans[a[i]] = u.first;
		u = to[i-1][u.first][u.second];
	}
	for(int i = 1; i <= n; i++){
		printf("%d ", Ans[i]);
	}
}
/*
3
3 2 3
4 3 2
3 1 3
1 2
1 3
*/