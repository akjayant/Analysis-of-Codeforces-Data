// clang-format off
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#ifndef bhartiya
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// typedef gp_hash_table<int, int> umap;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
// 		tree_order_statistics_node_update> oset;
// not that imp
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 200000000000000
#define MOD 1000000007
#define EPS 1e-7
#define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb push_back
#define bitc __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define sz(x) (int)(x).size()

#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x7f for inf, 0x80 for -INF can also use with pairs

#ifdef bhartiya
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(; ;i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<"| ";
	__f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e) {
	ll ans=1; for(;e;b=b*b%MOD,e/=2) if(e&1) ans=ans*b%MOD; return ans; }
// clang-format on

const int maxn = 1000005;

set<int> x[maxn]; // list of y at x = x
set<int> y[maxn]; // list of x
int xx1,yy1,xx2,yy2;

bool right(){
	if(sz(x[xx1]) == 0){
		xx1++;
		return true;
	}
	int to = *(x[xx1].begin());
	fr(i, xx1, xx2){
		fr(j,to,yy2){
			auto it = x[i].find(j);
			if(it == x[i].end()){
				return false;
			}
			x[i].erase(j);
			y[j].erase(i);
		}
	}
	xx1++;
	yy2 = to-1;
	return true;
}

bool left(){
	if(sz(x[xx2]) == 0){
		xx2--;
		return true;
	}
	auto it = x[xx2].end();
	it--;
	int to = *(it);
	fr(i, xx1, xx2){
		fr(j,yy1,to){
			auto it = x[i].find(j);
			if(it == x[i].end()){
				return false;
			}
			x[i].erase(j);
			y[j].erase(i);
		}
	}
	xx2--;
	yy1 = to+1;
	return true;
}


bool down(){
	trace(yy2);
	if(sz(y[yy2]) == 0){
		yy2--;
		return true;
	}
	int to = *(y[yy2].begin());
	fr(i, to, xx2){
		fr(j,yy1,yy2){
			auto it = x[i].find(j);
			if(it == x[i].end()){
				return false;
			}
			x[i].erase(j);
			y[j].erase(i);
		}
	}
	xx2 = to-1;
	yy2--;
	return true;
}

bool up(){
	if(sz(y[yy1]) == 0){
		yy1++;
		return true;
	}
	auto it = y[yy1].end();
	it--;
	int to = *(it);
	fr(i, xx1, to){
		fr(j,yy1,yy2){
			auto it = x[i].find(j);
			if(it == x[i].end()){
				return false;
			}
			x[i].erase(j);
			y[j].erase(i);
		}
	}
	xx1 = to+1;
	yy1++;
	return true;
}



void solve() 
{
	int n,m; cin>>n>>m;
	xx1 = 1, yy1 = 1, xx2 = n, yy2 = m;
	int k; cin>>k;
	rep(i,k){
		int a,b; cin>>a>>b;
		x[a].insert(b);
		y[b].insert(a);
	}
	bool flag = 1;
	while(true){
		if(xx1>xx2 || yy1 > yy2){
			break;
		}
		if(!right()){
			flag = 0;
			break;
		}
		if(xx1>xx2 || yy1 > yy2){
			break;
		}
		if(!down()){
			flag = 0;
			break;
		}
		if(xx1>xx2 || yy1 > yy2){
			break;
		}
		if(!left()){
			flag = 0;
			break;
		}
		if(xx1>xx2 || yy1 > yy2){
			break;
		}
		if(!up()){
			flag = 0;
			break;
		}
		if(xx1>xx2 || yy1 > yy2){
			break;
		}
	}
	if(flag){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(10);  // cout<<fixed;
#ifdef bhartiya
    cin.exceptions(cin.failbit);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t; 
    fr(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}