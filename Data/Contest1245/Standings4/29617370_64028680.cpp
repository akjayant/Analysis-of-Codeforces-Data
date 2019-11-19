#include<bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int g[2020][2020]; //il nodo n è fittizio, è il generatore
pipii edges[4400400];
int cnt=0;
pii coords[2020];
int k[2020];
int n;
int id[2020];


int root(int i){
	while(i != id[i]){
		id[i]=id[id[i]];
		i=id[i];
	}
	return i;
}

void merge(int i, int j){
	int a=root(i);
	int b=root(j);
	id[a]=b;
}

int32_t main(){
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> coords[i].first >> coords[i].second;
	}
	for(int i=0; i<n; ++i){
		int a; cin >> a;
		g[i][n]=a;
		g[n][i]=a;
		edges[cnt++]={a, {n, i}};
	}
	for(int i=0; i<n; ++i){
		cin >> k[i];
		for(int j=0; j<i; ++j){
			int val=abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second);
			val*=k[i]+k[j];
			g[i][j]=g[j][i]=val;
			edges[cnt++]={val, {i, j}};
		}
	}
	//mst
	for(int i=0; i<=n; ++i) id[i]=i;
	sort(edges, edges+cnt);
	int i=0;
	int tot=0;
	vector<int> gen;
	vector<pii> sol;
	while(i<cnt){
		int val=edges[i].first;
		int from=edges[i].second.first;
		int to=edges[i].second.second;
		if(root(from) != root(to)){
			merge(from, to);
			tot+=g[from][to];
			if(from == n || to == n){
				gen.push_back(min(from, to));
			}
			else {
				sol.push_back({from, to});
			}
		}
		++i;
	}
	cout << tot << endl;
	cout << gen.size() << endl;
	for(int o:gen) cout << o+1 << " ";
	cout << endl;
	cout << sol.size() << endl;
	for(pii o:sol) cout << o.first+1 << " " << o.second+1 << endl;
}
