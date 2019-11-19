#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define X first
#define Y second
#define pb push_back
#define int long long

const LL mod = 1e9 + 7;


template<class T>
istream& operator >> (istream& in, vector<T>& v){ for (auto &x : v) { in >> x; } return in; }

template<class T>
istream& operator >> (istream& in, pair<T, T> & v){ in >> v.X >> v.Y;return in; }

template<class T>
ostream& operator << (ostream& out, pair<T, T> & v){ out << v.X << " " << v.Y;return out; }

void chkmax(int &a, int b) {
    a = max(a, b);
    return;
}

void chkmin(int &a, int b) {
    a = min(a, b);
    return;
}

LL ppow (LL x, LL s) {
    if (!s) return 1;
    if (!(s - 1)) return x % mod;
    if (s % 2) return (x * ppow (x, s - 1)) % mod;
    LL b = ppow (x, s / 2);
    return (b * b) % mod;
}

const int MAXN = 4e6 + 100;

int link[MAXN], sz[MAXN];

int findd(int x) {
    return (x == link[x]) ? (x) : (link[x] = findd(link[x]));
}

int unite(int a, int b) {
    a = findd(a);
    b = findd(b);
    if (a == b) {
        return 0;
    }
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    sz[a] += sz[b];
    link[b] = a;
    return 1;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("ILUXA.in", "r", stdin);
    for (int i = 0;i < MAXN;i++) {
        link[i] = i;
        sz[i] = 1;
    }
    int n;
    cin >> n;
    vector<int> x(n), c(n), y(n), k(n);
    for (int i = 0;i < n;i++) {
        cin >> x[i] >> y[i];
    }
    cin >> c >> k;
    vector<pair<int,pair<int,int> > > edges;
    for (int i = 0;i < n;i++) {
        for (int j = i + 1;j < n;j++) {
            edges.pb({(k[i] + k[j])*(abs(x[i] - x[j]) + abs(y[i] - y[j])), {i, j}});
        }
    }
    for (int i = 0;i < n;i++) {
        edges.pb({c[i], {i, n}});
    }
    sort(all(edges));
    int ans = 0;
    vector<pair<int,int> > ans_e;
    vector<int> ans_v;
    for (auto x : edges) {
        if (unite(x.Y.Y, x.Y.X)) {
            ans += x.X;
            if (x.Y.Y == n) {
                ans_v.pb(x.Y.X);
            }else {
                ans_e.pb({x.Y.Y, x.Y.X});
            }
        }
    }
    cout << ans << '\n';
    cout << ans_v.size() << '\n';
    for (auto x : ans_v) {
        cout << x + 1 << " " ;
    }
    cout << '\n' << ans_e.size() << '\n';
    for (auto x : ans_e) {
        cout << x.X + 1 << " " << x.Y + 1 << '\n';
    }
    return 0;
}
