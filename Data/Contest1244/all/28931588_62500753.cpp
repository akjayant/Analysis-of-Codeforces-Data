#include<bits/stdc++.h>

using namespace std;

typedef long long INT;

#define NN 1000010

int c[10][NN];
int flag[NN];
vector<int> res;
int col[NN];
vector<int> adj[NN];

int dfs(int u) {
	res.push_back(u);
	for(auto v : adj[u]) if(!flag[v]) {
		flag[v] = 1;
		dfs(v);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
	cin >> n;
	
	for(int j=1; j<=3; j++) {
		for(int i=1; i<=n; i++) {
			scanf("%d", &c[j][i]);
		}
	}
	
	for(int i=1; i<n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i=1; i<=n; i++) if(adj[i].size() >= 3) return puts("-1"), 0;
	
	for(int i=1; i<=n; i++) if(adj[i].size() == 1) {
		flag[i] = 1;
		dfs(i);
		break;
	}
	
	INT ans = 0x3f3f3f3f3f3f3f3f;
	
	for(int i=1; i<=3; i++) for(int j=1; j<=3; j++) if(i != j) {
		int x = i; int y = j; int z;
		for(int k=1; k<=3; k++) if(k != i and k != j) z = k;
		INT tot = 0;
		for(int ii=0; ii<res.size(); ii++) {
			if(ii % 3 == 0) tot += c[x][res[ii]];
			if(ii % 3 == 1) tot += c[y][res[ii]];
			if(ii % 3 == 2) tot += c[z][res[ii]];
		}
		ans = min(ans, tot);
	}
	
	for(int i=1; i<=3; i++) for(int j=1; j<=3; j++) if(i != j) {
		int x = i; int y = j; int z;
		for(int k=1; k<=3; k++) if(k != i and k != j) z = k;
		INT tot = 0;
		for(int ii=0; ii<res.size(); ii++) {
			if(ii % 3 == 0) tot += c[x][res[ii]];
			if(ii % 3 == 1) tot += c[y][res[ii]];
			if(ii % 3 == 2) tot += c[z][res[ii]];
		}
		if(tot == ans) {
			cout << ans << endl;
			for(int ii=0; ii<res.size(); ii++) {
				if(ii % 3 == 0) col[res[ii]] = x;
				if(ii % 3 == 1) col[res[ii]] = y;
				if(ii % 3 == 2) col[res[ii]] = z;
			}
			for(int ii=1; ii<=n; ii++) printf("%d ", col[ii]);
			return 0;
		}
	}
	
	return 0;
}

        