#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define repi(i, a, b) for(int i=(a); i>(b); i--)
#define db(x) (cerr << #x << ": " << (x) << '\n')
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define cps CLOCKS_PER_SEC
#define tests(t) int t; cin >> t; while(t--)
#define iceil(n, x) (((n) + (x) - 1) / (x))
#define ll long long
#define gcd __gcd
#define eb emplace_back
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define sz size()
#define all(v) (v).begin(), (v).end()
#define uni(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define fi first
#define se second
#define mt make_tuple
#define pqueue priority_queue
#define bitcount(x) __builtin_popcount(x)
#define PI acos(-1.0)
#define EPS 1e-9
#define mod 1000000007
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

template<typename T1, typename T2>
ostream& operator << (ostream& os, const pair<T1, T2>& p) { return os << '(' << p.fi << ", " << p.se << ')'; }

template<typename T>
void printv(const T& v) { for(auto i : v) cerr << i << ' '; cerr << '\n'; }

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;

//All indexing is 0-based
using namespace __gnu_pbds;
template<class key, class cmp = std::less<key>>
using ordered_set = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
//methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

//Returns no. of values x for which ceil(n / x) == y (y must be > 1).
inline ll CC(ll n, ll y) { return iceil(n, y-1) - iceil(n, y); }

//Returns no. of values x for which floor(n / x) == y
inline ll FF(ll n, ll y) { return n / y - n / (y+1); }

//a and b are assumed to be taken modulo p
inline int add(int a, int b, int p = mod){ int c = a + b; if(c >= p) c -= p; return c; }
inline int sub(int a, int b, int p = mod){ int c = a - b; if(c < 0) c += p; return c; }
inline int mul(int a, int b, int p = mod){ return (a * 1ll * b) % p; }

#define N 500005
#define int ll
// #define trace(...) 42

const int inf = 1e18;

int n, c[N][3];
int dp[N][3][3];
pii sol[N][3][3];
int ans[N];
vi adj[N];

int dfs(int i, int j, int k, int p) {
    int& ans = dp[i][j][k];
    if(ans != -1) return ans;

    ans = inf;
    pii& pp = sol[i][j][k];

    int ch = 0;
    vi vc;
    for(int j : adj[i]) {
        if(j != p) {
            ++ch;
            vc.pb(j);
        }
    }

    if(vc.size() == 0) {
        return ans = c[i][j];
    }

    if(ch > 2) {
        cout << -1; exit(0);
    }

    if(i && ch > 1) {
        cout << -1; exit(0);
    }

    if(i) {
        ans = c[i][j] + dfs(vc[0], 3-j-k, j, i);
        pp = {3-j-k, -1};
    }
    else {
        if(ch == 1) {
            rep(k, 0, 3) {
                if(k != j) {
                    int kk = c[i][j] + dfs(vc[0], k, j, i);
                    if(ans > kk) {
                        ans = kk;
                        pp = {k, -1};
                    }
                }
            }
        }
        else {
            rep(k, 0, 3) {
                rep(l, 0, 3) {
                    if(k == l || k == j || l == j) continue;
                    int kk = c[i][j] + dfs(vc[0], k, j, i) + dfs(vc[1], l, j, i);
                    if(kk < ans) {
                        ans = kk;
                        pp = {k, l};
                    }
                }
            }
        }
    }

    // trace(i, j, k, ans, pp);
    return ans;
}

void print(int i, int j, int k, int p) {
    // trace(i, j, k, p);
    ans[i] = j;

    auto& pp = sol[i][j][k];

    int ch = 0;
    vi vc;
    for(int j : adj[i]) {
        if(j != p) {
            ++ch;
            vc.pb(j);
        }
    }

    if(ch == 0) return;
    if(ch == 1) {
        print(vc[0], pp.fi, j, i);
    }
    else {
        print(vc[0], pp.fi, j, i);
        print(vc[1], pp.se, j, i);
    }
}

main()
{   
    #ifndef ONLINE_JUDGE
        freopen("/home/tarun/Desktop/input.txt", "r", stdin);
     // freopen("/home/tarun/Desktop/output.txt", "w", stdout);
    #endif
    sync;
    clock_t clk = clock();
    cerr << "I will return...\n";

    cin >> n;
    rep(i, 0, 3) {
        rep(j, 0, n) cin >> c[j][i];
    }

    rep(i, 0, n-1) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    memset(dp, -1, sizeof dp);
    int ans = inf, l;

    rep(k, 0, 3) {
        int kk = dfs(0, k, 0, -1);
        if(kk < ans) {
            ans = kk;
            l = k;
        }
    }

    cout << ans << '\n';
    print(0, l, 0, -1);
    
    rep(i, 0, n) {
        cout << ::ans[i]+1 << ' ';
    } cout << '\n';

    cerr << "...don't you ever hang your head.\n";
    cerr << "Time (in ms): " << (double)(clock() - clk) * 1000.0 / cps << '\n';
}

//Compile using:
//g++ -o filename.exe --std=c++11 filename.cpp
//Use -D CP for defining a macro CP in the local environment


