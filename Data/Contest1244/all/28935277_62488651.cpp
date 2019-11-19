#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;
#define INF 499999999999999999LL
vector<int> grafo[MAXN];

typedef long long int lli;
lli custo[MAXN][5];
int n;
vector<int> ordem;


bool vis[MAXN];

void dfs(int v){
	if(vis[v]) return;
	vis[v] = 1;
	ordem.push_back(v);
	for(int u : grafo[v]){
		dfs(u);
	}
}

lli pd[MAXN][4][4];
int des[MAXN][4][4];

lli solve(int i, int a, int aa){
	
	if(i == n) return 0;
	if(pd[i][a][aa] != -1) return pd[i][a][aa];
	lli res = INF;
	for(int c = 1; c <= 3; c++){
		if(a != c and aa != c){
			lli ax = custo[ordem[i]][c] + solve(i+1,c,a);
			if(ax < res){
				des[i][a][aa] = c;
				res = ax;
			}
		}
	}
	return pd[i][a][aa] = res;
}


int corr[MAXN];
void recupera(int i, int a, int aa){
	if(i == n) return;
	int c = des[i][a][aa];
	corr[ordem[i]] = c;
	//cout << "pop" << c << " ";
	recupera(i+1,c,a);
}

int main (){
	//cout << INF << endl;
	
	cin >> n;
	
	for(int k = 1; k <= 3 ;k++){
		for(int i = 1; i <= n; i++){
			cin >> custo[i][k];
		}
	}
	bool ok = 1;
	for(int i = 1; i <= n-1; i++){
		int u, v;
		cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
		if(grafo[u].size() > 2) ok = 0;
		if(grafo[v].size() > 2) ok = 0;
	}
	
	if(!ok){
		cout << -1 << endl;
		return 0;
	}
	
	int ini = -1;
	for(int i = 1; i <= n; i++){
		if(grafo[i].size() == 1){
			ini = i;
		}
	}
	
	dfs(ini);
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= 3; j++){
			for(int k = 0; k <= 3; k++)
				pd[i][j][k] = -1;
		}
	}
	cout << solve(0,0,0) << endl;
	
	recupera(0,0,0);
	
	for(int i = 1; i <= n; i++){
		cout << corr[i] << " ";
	}
	
}




