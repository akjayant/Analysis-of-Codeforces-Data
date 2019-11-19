#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
set<ii> con;
int sz[100100] = {};
bool flag[100100] = {};
vector<int> grafo[100100];

void DFS(int x){
	for(int i = 0; i<grafo[x].size(); i++){
		int y = grafo[x][i];
		ii p(sz[y], y);
		if(con.find(p) == con.end()) continue;
		con.erase(con.find(p));
		p.first++;
		sz[y]++;
		con.insert(p);
	}
}

void print(){
	for(set<ii>::iterator it = con.begin(); it!=con.end(); it++){
		cout<<it->second<<"("<<it->first<<") ";
	}
	cout<<endl;
}

int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 0; i<m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		grafo[x].push_back(y);
		grafo[y].push_back(x);
	}

	for(int i = 2; i<=n; i++){
		ii p(sz[i],i);
		con.insert(p);
	}

	DFS(1);
	int tam = 1;
	int ans = 0;
	for(int i = 1; i<n; i++){
		if(con.begin()->first==tam){
			ans++;
		}
		int x = con.begin()->second;
		con.erase(con.begin());
		DFS(x);
		tam++;
	}
	cout<<ans<<endl;
}
