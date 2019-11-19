// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef bhartiya
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
// not that imp
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 1000000000000000000
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
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x7f for inf, 0x80 for -INF

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

int c[4][maxn];
int anser[maxn];
vi adj[maxn];


int findCost(int s, int p, int col1, int col2){
    int color = 0;
    int val = 0;
    fr(col, 1, 3){
        if(col != col1 && col != col2){
            color = col;
            val = c[col][s];
        }
    }
    for(auto ch: adj[s]) if(ch != p){
        val += findCost(ch, s, col2, color);
    }
    return val;
}

void mark(int s, int p, int col1, int col2){
    int color = 0;
    fr(col, 1, 3){
        if(col != col1 && col != col2){
            color = col;
        }
    }
    for(auto ch: adj[s]) if(ch != p){
        mark(ch, s, col2, color);
    }
    anser[s] = color;
}

void solve() 
{
    int ans = INF;
    int n;
    cin>>n;
    fr(i,1,n){
        cin>>c[1][i];
    }
    fr(i,1,n){
        cin>>c[2][i];
    }
    fr(i,1,n){
        cin>>c[3][i];
    }
    fr(i,1,n-1){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int leaf = 0;
    fr(i,1,n){
        if(sz(adj[i]) > 2){
            cout<<-1<<endl;
            return;
        }
        if(sz(adj[i]) == 1){
            leaf = i;
        }
    }
    int leaf2 = adj[leaf][0];
    int leaf3;
    for(auto ch: adj[leaf2]){
        if(ch != leaf) leaf3 = ch;
    }
    fr(i,1,3){
        fr(j,1,3){
            if(i == j) continue;
            int val = c[i][leaf] + c[j][leaf2] + findCost(leaf3, leaf2, i, j);
            if(ans > val){
                ans = val;
                anser[leaf] = i;
                anser[leaf2] = j;
                mark(leaf3, leaf2, i ,j);
            }
        }
    }
    trace(leaf, leaf2);
    cout<<ans<<endl;
    fr(i,1,n){
        cout<<anser[i]<<" ";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(10);  // cout<<fixed;
    cin.exceptions(cin.failbit);
#ifdef bhartiya
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