#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100100;

int n, m;
bool pro[MAXN];
set<int> g[MAXN], s;

void dfs(int v){
	vector<int> aux;
	for(auto i : s){
		if(g[v].find(i) != g[v].end())
			continue;
		aux.push_back(i);
	}
	for(auto u : aux)
		s.erase(u);
	for(auto u : aux)
		dfs(u);
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n;i++)
		s.insert(i);
	for(int i = 1, a, b;i <= m;i++)
		scanf("%d %d", &a, &b), g[a].insert(b), g[b].insert(a);
	
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(s.find(i) != s.end()){
			s.erase(i);
			dfs(i);
			ans++;
		}
	}
	printf("%d",  ans - 1);
}