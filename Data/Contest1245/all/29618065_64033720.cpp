#include <bits/stdc++.h>
//#include <bits/extc++.h>

#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector<int> vec;
typedef vector<vec> grid;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const double eps = 1e-8;
const int INF32 = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int mod2 = 998244853;
const int N = 2e3 + 5;
const int sz = (1 << 20);

struct node {
    int x, y;
} point[N];

struct cc {
    int w, id;
} co[N];

struct obj {
    int u, v;
    ll w;
};

struct cmp {
    bool operator()(obj a, obj b) {
        return a.w > b.w;
    }
};

bool cmp1(cc a, cc b) {
    return a.w < b.w;
}

int vis[N], c[N], n;
ll k[N], ans;

vector<int> ver;
vector<pii> edge;

void bfs(int s) {
    priority_queue<obj, vector<obj>, cmp> heap;
    heap.push({0, s, c[s]});
    while (!heap.empty()) {
        auto p = heap.top();
        heap.pop();
        if (vis[p.v] || p.w > c[p.v])
            continue;

        ans += p.w;
        vis[p.v] = 1;
        if (p.u)
            edge.emplace_back(p.u, p.v);
        else
            ver.emplace_back(p.v);

        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                heap.push({p.v, i, (k[i] + k[p.v]) * (abs(point[i].x - point[p.v].x) + abs(point[i].y - point[p.v].y))});
                heap.push({0, i, c[i]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MYDEBUG
    freopen("../0in.txt", "r", stdin);
//    freopen("../0out.txt", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> point[i].x >> point[i].y;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> co[i].w;
        c[i] = co[i].w;
        co[i].id = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
    }
    sort(co + 1, co + n + 1, cmp1);
    for (int i = 1; i <= n; ++i) {
        if (!vis[co[i].id]) {
            bfs(co[i].id);
        }
    }
    cout << ans << endl << ver.size() << endl;
    for (int i : ver)
        cout << i << ' ';
    cout << endl << edge.size() << endl;
    for (pii i : edge)
        cout << i.first << ' ' << i.second << endl;
    return 0;
}