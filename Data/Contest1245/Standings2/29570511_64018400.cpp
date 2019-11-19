#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define ld long double
#define ll long long
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define endl '\n'

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 2e3 + 10;
const ll MOD = 1e9 + 7;
const int rx[4] = {-1, 0, 1, 0};
const int ry[4] = {0, 1, 0, -1};
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int hx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int hy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const ld eps = 1e-7;
const double pi = acos(-1.0);
const int INF = 2e9;

vector <pair <ll, pair <int, int> > > rgs;

ll ans = 0;

vector <pair <int, int> > ans2;
bool used[N];

int parent[N], sz[N];
pair <int, int> mn[N];

int find_set(int a) {
    return (a == parent[a] ? a : parent[a] = find_set(parent[a]));
}

void unite_sets(int a, int b, ll rast) {
    int za = a, zb = b;
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (mn[a].F + mn[b].F < min(mn[a].F, mn[b].F) + rast) return;
        ans += rast;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        mn[a] = min(mn[a], mn[b]);
        ans2.pb({za + 1, zb + 1});
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    ll c[n], k[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
        cin >> c[i];
        mn[i] = {c[i], i};
    }
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            rgs.pb({(k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), {i, j}});
        }
    }
    sort(rgs.begin(), rgs.end());
    for (auto it : rgs) {
        unite_sets(it.S.F, it.S.S, it.F);
    }
    vector <int> roots;
    for (int i = 0; i < n; i++) {
        int pr = find_set(i);
        if (!used[pr]) {
            used[pr] = true;
            roots.pb(mn[pr].S + 1);
            ans += mn[pr].F;
        }
    }
    cout << ans << endl;
    cout << roots.size() << endl;
    for (auto it : roots) cout << it << " ";
    cout << endl;
    cout << ans2.size() << endl;
    for (auto it : ans2) cout << it.F << " " << it.S << endl;
    return 0;
}

