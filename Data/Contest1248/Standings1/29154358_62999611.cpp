#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 1e6 + 100;
vector<int> G[maxn],val[maxn],ans1,ans2,tmp;
inline void addedge(int from,int to){G[from].push_back(to);}
int t,n,m,dfn[maxn],low[maxn],instk[maxn],col[maxn],deg[maxn],dfs_tot,col_tot;
stack<int> stk;
inline void clear(){
	ans1.clear();
	ans2.clear();
	for(int i = 1;i <= n;i++)
		G[i].clear(),val[i].clear(),deg[i] = dfn[i] = low[i] = instk[i] = col[i] = 0;
	dfs_tot = col_tot = 0;
}
inline void tarjan(int u){
	dfn[u] = low[u] = ++dfs_tot;
	stk.push(u);instk[u] = 1;
	for(int v : G[u])
		if(!dfn[v])tarjan(v),low[u] = min(low[u],low[v]);
		else if(instk[v])low[u] = min(low[u],dfn[v]);
	if(dfn[u] == low[u]){
		int t;
		col_tot++;
		do{
			t = stk.top();stk.pop(),instk[t] = 0;
			col[t] = col_tot;
			val[col_tot].push_back(t);
		}while(t != u);
	}
}
inline void solve(){
	clear();
	cin >> n >> m;
	for(int u,v,i = 1;i <= m;i++){
		cin >> u >> v;
		if(u != v)addedge(u,v);
	}
	for(int i = 1;i <= n;i++)
		if(!dfn[i])tarjan(i);
	for(int u = 1;u <= n;u++)
		for(int v : G[u])
			if(col[u] != col[v])deg[col[u]]++;
	for(int i = 1;i <= col_tot;i++)
		if(!deg[i])ans1.push_back(i);
		else ans2.push_back(i);
	if(ans1.empty()){
		cout << "No" << '\n';
		return;
	}
	if(ans2.empty())ans2.push_back(ans1.back()),ans1.pop_back();
	if(ans1.empty()){
		cout << "No" << '\n';
		return;
	}
	cout << "Yes" << '\n';
	tmp.clear();
	for(auto x : ans1)
		for(auto y : val[x])
			tmp.push_back(y);
	cout << tmp.size() << " ";
	
	tmp.clear();
	for(auto x : ans2)
		for(auto y : val[x])
			tmp.push_back(y);
	cout << tmp.size() << "\n";
	
	tmp.clear();
	for(auto x : ans1)
		for(auto y : val[x])
			tmp.push_back(y);
	for(auto x : tmp)
		cout << x << " ";
	cout << '\n';
	
	tmp.clear();
	for(auto x : ans2)
		for(auto y : val[x])
			tmp.push_back(y);
	for(auto x : tmp)
		cout << x << " ";
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)solve();
	return 0;
}

