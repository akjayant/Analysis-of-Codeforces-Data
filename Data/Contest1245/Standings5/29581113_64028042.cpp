#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = 1'000'000'007; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}

#define x first
#define y second
#define MAX_E 5100000
#define MAX_V 3000

vector<pair<int,int>> ans1;
vector<int> ans2;

struct edge{int u, v, cost;};

bool comp(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}
int V, E;
int n;
edge es[MAX_E];
int par[MAX_V];
int _rank[MAX_V];

void init(int x){
	for(int i = 0; i < x; i++){
		par[i] = i;
		_rank[i] = 0;
	}
}

int find(int x){
	return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y){
	x = find(x);
	y = find(y);
	
	if(x == y) return;
	
	if(_rank[x] < _rank[y]){
		par[x] = y;
	} else{
		par[y] = x;
		if(_rank[x] == _rank[y]) _rank[x]++;
	}
}

bool same(int x, int y){
	return find(x) == find(y);
}

int kruskal(){
	sort(es, es + E, comp);
	init(V);
	int res = 0, count = 0;
	// for(int i = 0; i < E && count != V-1; i++){
	for(int i = 0; i < E; i++){
		edge e = es[i];
		if(!same(e.u, e.v)){
			if(e.u != n && e.v != n){
				if(e.u <= e.v)ans1.push_back(make_pair(e.u, e.v));
				else ans1.push_back(make_pair(e.v, e.u));
			} else {
				if(e.v != n) ans2.push_back(e.v);
				else ans2.push_back(e.u);
			}
			unite(e.u,e.v);
			res += e.cost;
			count++;
		}
	}
	return res;
}

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int count = 0;
	vector<pair<int,int>> co;
	vector<int> cost, k;
	
	cin>>n;
	
	V = n+1;
	
	co.resize(n+1);
	cost.resize(n+1);
	k.resize(n+1);
	
	for(int i = 0; i < n; i++){
		cin>>co[i].x>>co[i].y;
	}
	
	for(int i = 0; i < n; i++){
		cin>>cost[i];
	}
	
	for(int i = 0; i < n; i++){
		cin>>k[i];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int c = (abs(co[i].x - co[j].x) + abs(co[i].y - co[j].y)) * (k[j] + k[i]);
			es[count++] = {i, j, c};
		}
	}
	
	for(int i = 0; i < n; i++){
		es[count++] = {n, i, cost[i]};
	}
	
	E = count;
	
	cout<<kruskal()<<endl;
	
	sort(ans1.begin(), ans1.end());
	ans1.erase(unique(ans1.begin(), ans1.end()), ans1.end());
	
	sort(ans2.begin(), ans2.end());
	ans2.erase(unique(ans2.begin(), ans2.end()), ans2.end());
	
	cout<<ans2.size()<<endl;
	
	for(int i = 0; i < ans2.size(); i++){
		if(i) cout<<" ";
		cout<<ans2[i]+1;
	}
	cout<<endl;
	
	cout<<ans1.size()<<endl;
	
	for(int i = 0; i < ans1.size(); i++){
		cout<<ans1[i].first+1<<" "<<ans1[i].second+1<<endl;
	}
	return 0;
}