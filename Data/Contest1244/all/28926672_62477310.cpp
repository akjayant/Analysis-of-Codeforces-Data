#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 5;

int n, c[3][MAXN];
vector<int> adj[MAXN];
int col[6][MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &c[0][i+1]);
	}
	for(int j = 0; j < n; ++j){
		scanf("%d", &c[1][j+1]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%d", &c[2][i+1]);
	}
	for(int i = 0; i < n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int st = -1;
	for(int i = 1; i <= n; ++i){
		if(adj[i].size() > 2){
			printf("-1\n");
			return 0;
		}else if(adj[i].size() == 1){
			st = i;
		}
	}
	vector<int> line;
	int cur = st, prev = -1;
	for(int i = 0; i < n; ++i){
		line.push_back(cur);
		for(auto j : adj[cur]) if(j != prev){
			prev = cur;
			cur = j;
			break;
		}
	}
	long long ans[] = {0, 0, 0, 0, 0, 0};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 3; ++j){
			ans[(i+j)%3] += c[j][line[i]];
			col[(i+j)%3][line[i]] = j+1;
			ans[3+(i-j+3)%3] += c[j][line[i]];
			col[3+(i-j+3)%3][line[i]] = j+1;
		}
	}
	// 0, 
	int minim = 0;
	for(int i = 0; i < 6; ++i)
		if(ans[minim] > ans[i])
			minim = i;
	printf("%lld\n", ans[minim]);
	for(int i = 1; i <= n; ++i){
		if(i > 1)
			printf(" ");
		printf("%d", col[minim][i]);
	}
	printf("\n");
}