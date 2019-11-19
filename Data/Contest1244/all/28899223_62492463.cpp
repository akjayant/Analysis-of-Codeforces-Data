#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<map>
#include<unordered_map>
#ifdef LOCAL
#include"file.h"
#endif

#define y1 zyy_orz
#define hash sto_zyy

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL>pLL;
typedef pair<int, int>pii;
const double eps = 1e-10;
const double Pi = 3.1415926535897932;
const int dir[4][2] = { -1,0,0,-1,1,0,0,1 };
//const int dir[8][2] = { -2,-1,-2,1,2,-1,2,1,-1,2,-1,-2,1,2,1,-2 };










const int maxn = 1e5 + 5;

int cost[5][maxn];

vector<int>G[maxn];
LL f[maxn][5][5];
int n;
int belong[maxn];

int pos[maxn];

void dfs(int a, int fa,int d) {
	pos[d] = a;
	for (int i = 0; i < G[a].size(); i++) {
		const int &b = G[a][i];
		if (b == fa)continue;
		dfs(b, a, d + 1);
	}
}

int main() {
#ifdef LOCAL
	fileopen();
#endif
	scanf("%d", &n);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bool ok = true;
	int p;
	for (int i = 1; i <= n; i++) {
		if (G[i].size() >= 3) {
			ok = false;
			break;
		}
		if (G[i].size() == 1)p = i;
	}
	if (!ok) {
		printf("-1\n");
		return 0;
	}

	dfs(p, -1, 1);

	for (int i = 1; i <= n; i++) {
		for (int last = 1; last <= 3; last++) {
			for (int c = 1; c <= 3; c++)if (c != last) {
				f[i][c][last] = f[i - 1][last][6 - c - last] + cost[c][pos[i]];
			}
		}
	}
	
	LL ans = 1e18, a, b;
	for (int i = 1; i <= 3; i++) 
		for (int j = 1; j <= 3; j++)if(i!=j) {
			if (ans > f[n][i][j]) {
				ans = f[n][i][j];
				a = i; b = j;
			}
	}

	belong[pos[n]] = a;
	belong[pos[n - 1]] = b;
	for (int i = n - 2; i >= 1; i--)
		belong[pos[i]] = 6 - belong[pos[i+1]] - belong[pos[i+2]];
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++)printf("%d ", belong[i]);

#ifdef LOCAL
	fileclose();
#endif
	return 0;
}


