#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define sync ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
#define fr(x, n) for (int x = 0; x < n; x++)
#define int long long
#define pb push_back
#define y1 fadasdsadassa
#define random mt19937 rng(time(nullptr));

using namespace std;

const double eps = 1e-9;
const double EPS = 1e-17; 
const int M = 1e5 + 1;
const int INF = 1e17 + 7;
const int MOD = 1e9 + 7;
const int inf = 1e9 + 7;
const int N = 2 * 1e3 + 11;

vector <int> gr[N];

int c[N];
int p[N];
int sz[N];
int mn[N];
int len[N];
int k[N];
int L[N][N];
bool used[N];
int cap[N];

void make(int x) {
    sz[x] = 1;
    p[x] = x;
    cap[x] = x;
    mn[x] = c[x];
    len[x] = 0;
}

int find(int x) {
    if (x == p[x]) 
        return p[x];
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    int xx = x, yy = y;
    x = find(x); y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    p[y] = x;
    if (mn[x] > mn[y]) {
        cap[x] = cap[y];
    }
    mn[x] = min(mn[x], mn[y]);
    len[x] += len[y] + (k[xx] + k[yy]) * (L[xx][yy]); 
}

int _D(int x, int y, int xx, int yy) {
    return abs(x - xx) + abs(y - yy);
}

signed main () { sync;
    int n;
    cin >> n;
    vector <pair <int, int> > v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++) {
        make(i);   
    }
    vector <pair <int, pair <int, int> > > e;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            e.push_back({(k[i] + k[j]) * (_D(v[i].first, v[i].second, v[j].first, v[j].second)), {i, j}});
            L[i][j] = L[j][i] = _D(v[i].first, v[i].second, v[j].first, v[j].second);
        }

    }
 
    sort(e.begin(), e.end());

    int m = (int)e.size();

    vector <pair <int, int> > E;

    for (int i = 0; i < m; i++) {
        int x, y;
        int W = e[i].first;
        x = e[i].second.first;
        y = e[i].second.second;
        int xx = x, yy = y;
        x = find(x);
        y = find(y);
        if (x == y) continue;
        if (mn[x] + mn[y] >= W + min(mn[x], mn[y])) {
            merge(xx, yy);
            E.push_back({xx, yy});
        }
    }

    int ans = 0;

    vector <int> C;

    for (int i = 0; i < n; i++) {
        int x = find(i);
        if (!used[x]) {
            ans += mn[x] + len[x];
            C.push_back(cap[x]);
            used[x] = 1;
        }
    }

    cout << ans << '\n';
    cout << C.size() << '\n';
    for (auto it : C) cout << it + 1 << ' '; cout << '\n';
    cout << E.size() << '\n';
    for (auto it : E) cout << it.first + 1 << ' ' << it.second + 1 << '\n';
}
