#include <bits/stdc++.h>
using namespace std;
#define asp " " 
#define aps ''
#define one 1
#define two 2
#define dif !=
typedef long long ll;
typedef pair<ll,ll> ii;
const int maxn = 2005;
struct Edge{
	ll custo;
	int u,v;
};
vector<Edge> lista;
vector<ii> dist;
vector<ll> build;
vector<ll> km;
vector<ii> solution;
vector<int> parent(maxn);

bool comp(Edge a, Edge b){

	if(a.custo dif b.custo) return a.custo < b.custo;
	else return false;
}

ll calc(int u,int v){

	ll ret = abs(dist[u].first - dist[v].first);
	ret += abs(dist[u].second - dist[v].second);

	return ret;
}

void makes(int n){
	lista.clear();
	Edge aux;
	for(int i=0;i<n;i++){
		for(int j=i+one;j<n;j++){
			ll dist = calc(i,j);
			//cout << dist << endl;
			dist = dist*km[i] + dist*km[j];
			aux.custo = dist;
			//cout << aux.custo << endl;
			aux.u = i;
			aux.v = j;
			lista.push_back(aux);
		}
	}
	//cout  << endl;
	sort(lista.begin(),lista.end(),comp);
}

void preProcess(int n){

	for(int i=0;i<n;i++){
		solution.push_back({i,build[i]});
		parent[i] = i;
	}
}

int find(int u){

	if(u == parent[u]) return u;
	parent[u] = find(parent[u]);
	return parent[u];
}

bool isSameSet(int u,int v){

	return (find(u) == find(v));
}

void unionSet(int u,int v){

	u = find(u);
	v = find(v);

	parent[u] = parent[v];
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		dist.push_back({x,y});
	}

	ll sum = 0;
	int total = n;

	for(int i=0;i<n;i++){
		ll a;
		cin >> a;
		sum += a;
		build.push_back(a);
	}
	for(int i=0;i<n;i++){
		ll a;
		cin >> a;
		km.push_back(a);
	}

	makes(n);
	preProcess(n);
	int con = 0;

	vector<ii> ans;
	for(int i=0;i<lista.size();i++){
		ll custo = lista[i].custo;
		int u = lista[i].u;
		int v = lista[i].v;
		int pai_u,pai_v;
		int merg;

		if(isSameSet(u,v) == false){
			pai_u = find(u);
			pai_v = find(v);
			//cout << u << " " <<  v << endl;
			//cout << custo << endl;
			if(custo <= max(solution[pai_u].second,solution[pai_v].second)){
				unionSet(u,v);
				merg = find(u);
				con++;
				sum -= max(solution[pai_u].second,solution[pai_v].second);
				sum += custo;
				total--;
				ans.push_back({u+one,v+one});

				if(solution[pai_u].second <= solution[pai_v].second){
					solution[merg] = solution[pai_u];
				}
				else{
					solution[merg] = solution[pai_v];
				}
			}
		}
	}
	cout << sum << endl;
	cout << total << endl;
	set<int> all;

	for(int i=0;i<n;i++){
		int sss = find(i);
		sss = solution[sss].first;
		//cout << sss << endl;
		all.insert(sss);
	}

	for(auto v: all){
		cout << v+one << " ";
	}
	cout << endl;

	cout << con << endl;

	for(int i=0;i<con;i++){
		cout << ans[i].first << " " << ans[i].second << endl; 
	}
}