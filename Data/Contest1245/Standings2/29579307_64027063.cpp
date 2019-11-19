#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> ii;

struct DisjointSet{
	vector<int> p, m;
	void init(int n, vector<int>& c){
		p.resize(n); m.assign(n, 0);
		for(int i=0; i< n; ++i) m[i] = i, p[i] = i;
	}
	int root(int i){
		return p[i] == i ? i : p[i]=root(p[i]);
	}
	bool unify(int i, int j, int w, vector<int>& c){
		int x=  root(i), y = root(j);
		if(x == y) return false;
		if(c[m[x]] + c[m[y]] <= w + min(c[m[x]], c[m[y]])) return false;
		else{
			p[x] = y;
			if(c[m[x]] < c[m[y]]) m[y] = m[x];
			return true;
		}
	}
};

const int MAXN = 2E3+1;

int n;
vector<pair<int, ii> > edges;
vector<ii> pos(MAXN);
vector<int> cost(MAXN), c(MAXN);
DisjointSet dsu;
int ans;
vector<ii> cons;
vector<int> elec;


signed main(){
	cin >> n;
	for(int i=0; i< n; ++i){
		cin >> pos[i].first >> pos[i].second;
	}
	for(int i=0; i< n; ++i){
		cin >> c[i];
	}
	for(int i=0; i< n; ++i){
		cin >> cost[i];
	}
	for(int i=0; i< n; ++i)
		for(int j=i+1; j< n; ++j)
			edges.push_back({(cost[i]+cost[j])*(abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second)), {i, j}});
	sort(edges.begin(), edges.end());
	dsu.init(n, c);
	for(pair<int, ii> e : edges){
		bool t = dsu.unify(e.second.first, e.second.second, e.first, c);
		if(t) ans += e.first;
		if(t) cons.push_back({e.second.first+1, e.second.second+1});
	}
	for(int i=0; i< n; ++i){
		if(dsu.root(i) == i){
			ans += c[dsu.m[i]];
			elec.push_back(dsu.m[i]+1);
		}
	}
	cout << ans << "\n";
	cout << elec.size() << "\n";
	for(int x: elec) cout << x << " ";
	cout << "\n" <<cons.size()<< "\n";
	for(ii x: cons) cout << x.first << " " << x.second << "\n";
}
