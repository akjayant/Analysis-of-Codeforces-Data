#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}


const int N = 200005;
int n , m;
set<int> vis;
set<int> adj[N];
set<int> radj[N];

struct edge{
	int u, v; 
};

class dsu{
public:
	void init(int N){
		pai.clear() , peso.clear();
		pai.resize(N + 1) , peso.resize(N + 1);
		for(int i = 0 ; i <= N ; i ++){
			pai[i] = i , peso[i] = 1;
		}
	}
	int fd(int x){
		return pai[x] == x ? x : pai[x] = fd(pai[x]);
	}
	int get_sz(int x){
		return peso[fd(x)];
	}
	void join(int u ,int v){
		u = fd(u) , v = fd(v);
		if(peso[u] < peso[v]) swap(u,v);
		pai[v] = u , peso[u] += peso[v];
	}
private:
	vector<int> pai , peso;
};
dsu T;

void dfs(int x){
	vis.erase(x);
	auto u = vis.begin();
	while(u != vis.end()){
		int nx = *u;
		if(!adj[x].count(nx)){
			T.join(x , nx);
			dfs(nx);
		}
		u = vis.upper_bound(nx);
	}
}



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin>>n>>m;
	for(int i = 1 ; i <= n; i ++) vis.insert(i);
	T.init(n);
	vector<edge> v;
	for(int i = 0 ; i < m ; i ++){
		int x, y;
		cin>>x>>y;
		adj[x].insert(y);
		adj[y].insert(x);
		v.push_back({x,y});
	}
	for(int i = 1 ; i <= n; i ++){
		if(vis.count(i)) dfs(i);
	}
	int ans = 0;
	for(auto w : v){
		if(T.fd(w.u) != T.fd(w.v)){
			T.join(w.u , w.v);
			ans++;
		}
	}
	cout<<ans<<endl;
}