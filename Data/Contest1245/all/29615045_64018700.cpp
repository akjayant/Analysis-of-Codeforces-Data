#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}

struct UnionFindSize {
    vector<int> par;
    
    UnionFindSize(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

struct edge{
	ll s, t, w;
	bool operator<(const edge &right)const{
		return w < right.w;
	}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<pll> ten(n);
    REP(i, n){
    	cin >> ten[i].first >> ten[i].second;
    }
    vector<ll> c(n), k(n);
    REP(i, n) cin >> c[i];
    REP(i, n) cin >> k[i];

    UnionFindSize uf(n+1);

    vector<edge> edges;
    REP(i, n){
    	edge e = {i, n, c[i]};
    	edges.push_back(e);
    }
    REP(i, n){
    	REP(j, n){
    		if(i<j){
    			ll dist = abs(ten[i].first - ten[j].first) + abs(ten[i].second - ten[j].second);
    			edge e = {i, j, (k[i]+k[j])*dist};
    			edges.push_back(e);
    		}
    	}
    }
    sort(edges.begin(), edges.end());

    ll res = 0;
    vector<ll> tateru;
    vector<pll> tsuna;
    REP(i, edges.size()){
    	ll s = edges[i].s;
    	ll t = edges[i].t;
    	ll w = edges[i].w;
    	if(uf.merge(s, t)){
    		res += w;
    		if(t==n){
    			tateru.push_back(s);
    		}else{
    			tsuna.push_back({s, t});
    		}
    	}
    }

    cout << res << endl;
    cout << tateru.size() << endl;
    REP(i, tateru.size()) cout << tateru[i]+1 << " ";
    cout << endl;
    cout << tsuna.size() << endl;
    REP(i, tsuna.size()) cout << tsuna[i].first+1 << " " << tsuna[i].second+1 << endl;

    return 0;
}