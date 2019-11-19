#include <bits/stdc++.h>
using namespace std;

string to_string(bool x) {
    return x ? "true" : "false";
}

string to_string(char x) {
    return string(1, x);
}

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char *s) {
    return to_string((string) s);
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {
    cerr << endl;
}

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define fi first
#define se second
#define two(a) (1LL << (a))
#define has(mask, i) ((mask >> i) & 1)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector < int >;
using vll = vector < ll >;
using vvi = vector < vector < int > >;
using vpii = vector < pii >;
using ld = long double;
using vs = vector < string >;

mt19937_64 rnd((unsigned long) chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 1e5 + 9;

int parent[MAXN], ranks[MAXN];

void make_set (int v) {
    parent[v] = v;
    ranks[v] = 0;
}
 
int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (ranks[a] < ranks[b])
            swap (a, b);
        parent[b] = a;
        if (ranks[a] == ranks[b])
            ++ranks[a];
    }
}


vvi gg;
ll curMin = 0;
int curV = -1;
bool used[MAXN];
ll cc[MAXN];
bool was[MAXN];

void dfs(int v) {
    used[v] = 1;
    if(curMin > cc[v]) {
        curV = v;
        curMin = min(curMin, cc[v]);
    }
    for(auto to : gg[v])
        if(!used[to])
            dfs(to);
}

void solve() {
    int n; cin >> n;
    vi xx(n), yy(n);
    for(int i = 0; i < n; i++) {
        make_set(i);
        cin >> xx[i] >> yy[i];
    }
    make_set(n);

    vector < pair < ll, pair < int, int > > > ee;
    
    for(int i = 0; i < n; i++) cin >> cc[i];
    vll kk(n);
    for(auto &x : kk) cin >> x;

    for(int i = 0; i < n; i++) {
        {
            pii cur = {n, i};
            ee.pb(make_pair(cc[i], cur));
        }
        for(int j = i + 1; j < n; j++) {
            {
                pii cur = {j, i};
                ll dist = abs(xx[i] - xx[j]) + abs(yy[i] - yy[j]);
                ll cost = (kk[i] + kk[j]) * dist;
                ee.pb(make_pair(cost, cur));
            }
        }
    }

    gg.resize(n);

    ll ans = 0;
    vpii ansE;

    sort(all(ee));
    for(int i = 0; i < sz(ee); i++) {
        int a = ee[i].se.fi;
        int b = ee[i].se.se;

        int u = find_set(a);
        int v = find_set(b);

        if(u != v) {
            union_sets (a, b);
            if(a != n && b != n) {
                gg[a].pb(b);
                gg[b].pb(a);

                ansE.pb(make_pair(a + 1, b + 1));

                ll dist = abs(xx[a] - xx[b]) + abs(yy[a] - yy[b]);
                ll cost = (kk[a] + kk[b]) * dist;
                ans += cost;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        curMin = LONG_LONG_MAX;
        curV = -1;
        if(!used[i]) {
            dfs(i);
            ans += curMin;
            was[curV] = 1;
        }
    }

    cout << ans << endl;

    vi res;
    for(int i = 0; i < n; i++) if(was[i]) res.pb(i);

    cout << sz(res) << endl;
    for(auto x : res) cout << x + 1 << ' ';
    cout << endl;

    cout << sz(ansE) << endl;
    for(auto x : ansE) cout << x.fi << ' ' << x.se << endl;

}

int main() {
#ifdef LOCAL
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
    auto start_time = clock();
#else
    // ???
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(12);
    cerr.setf(ios::fixed | ios::showpoint);
    cerr.precision(4);

    solve();

#ifdef LOCAL
    auto end_time = clock();
    cerr << "time: " << (end_time - start_time) * 1.0 / CLOCKS_PER_SEC << endl;
#endif

    return 0;
}