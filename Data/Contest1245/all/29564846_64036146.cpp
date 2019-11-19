#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
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
#define int long long
const int N = 8002;
int x[N] , c[N] , k[N] , y[N];

struct edge{
	int u  , v, w;
	bool operator<(const edge & b) const {
		if(w == b.w){
			if(u == b.u){
				return v < b.v;
			}
			return u < b.u;
		}
		return w > b.w;
	}
}; 

class dsu{
public:
	void init(int N){
		pai.clear() , peso.clear();
		pai.resize(N + 1) , peso.resize(N + 1);
		cor.resize(N+1);
		for(int i = 0 ; i <= N ; i ++){
			pai[i] = i , peso[i] = 1;
			cor[i] = 0;
		}
	}
	int fd(int x){
		return pai[x] == x ? x : pai[x] = fd(pai[x]);
	}
	int get_cor(int x){
		return cor[fd(x)];
	}
	int give_cor(int x){
		return cor[fd(x)] = 1;
	}
	void join(int u ,int v){
		u = fd(u) , v = fd(v);
		if(peso[u] < peso[v]) swap(u,v);
		cor[v] |= cor[u] , cor[u] |= cor[v];
		pai[v] = u , peso[u] += peso[v];
	}
private:
	vector<int> pai , peso , cor;
};
dsu T;
int n;
vector<edge> v[N];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin>>n;
	priority_queue<edge> S;
	T.init(4*n);
	for(int i =  1 ; i <= n; i ++){
		cin>> x[i] >> y[i];
	}
	for(int i = 1 ; i <= n; i ++){
		cin>> c[i];
	}
	for(int i = 1 ; i <= n ; i ++){
		cin>> k[i];
	}
	for(int i = 1 ; i <= n; i ++){
		for(int j = 1 ; j <= n; j ++){
			if(j != i){
				int u = abs(x[i] - x[j]) + abs(y[j] - y[i]);
				u = (u * (k[i] + k[j]));
				v[i].push_back({i , j , u});
			}
		}
	}
	for(int i = 1 ; i <= n; i ++){
		S.push({i , i+n , c[i]});
	}
	for(int i = n + 1 ; i <= 2*n ; i ++){
		T.give_cor(i);
	}
	int ans = 0;
	vector<int> ln;
	vector<edge> cn;
	while(!S.empty()){
		edge w = S.top();
		S.pop();
		if((T.get_cor(w.u) && T.get_cor(w.v)) || (!T.get_cor(w.u) && !T.get_cor(w.v))) continue;
		T.join(w.u , w.v);	
		ans += w.w;
		for(auto r : v[w.u]){
			if(T.get_cor(r.u) != T.get_cor(r.v))
			S.push(r);
		}
		v[w.u].clear();
		for(auto r : v[w.v]){
			if(T.get_cor(r.u) != T.get_cor(r.v))
			S.push(r);
		}
		v[w.v].clear();
		if(w.v > n){
			ln.push_back(w.u);
		}
		else{
			cn.push_back(w);
		}
	}
	cout<<ans<<endl;
	cout<<ln.size() << endl;
	for(auto w : ln){
		cout<<w<<" ";
	}
	cout<<endl;
	cout<<cn.size() << endl;
	for(auto w : cn){
		cout<<w.u <<" " << w.v << endl;
	}
}
