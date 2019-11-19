//In the name of God
#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

map<pii, bool> g;
int n, m;

int get(vector<int> vec){
	vector<int> help;
	help.push_back(vec.back());	vec.pop_back();
	while(help.size()){
		map<int, bool> mark;
		int x = help.back();
		help.pop_back();
		vector<int> tof;
		for(auto u : vec){
			if(g[{u, x}] == 1)
				mark[u] = 1;
		}
		for(auto u : vec){
			if(mark[u] == 1)
				tof.push_back(u);
			else
				help.push_back(u);
		}
		vec = tof;
	}
	if(vec.empty())	return 0;
	else
		return 1 + get(vec);
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		g[{u, v}] = g[{v, u}] = 1;
	}
	vector<int> vec;
	for(int i = 1; i <= n; i ++)
		vec.push_back(i);
	cout << get(vec); 
	return 0;
}
