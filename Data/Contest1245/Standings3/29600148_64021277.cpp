#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define DEBUG(X) { cout << #X << " = " << X << endl; }
#define PR(A, n) { cout << #A << " = "; FOR(_, 1, n) cout << A[_] << " "; cout << endl;}

template <typename T> void Read(T &x) {
    x = 0; char c;
    bool sign = false;
    do {
        c = getchar();
    } while (!isdigit(c) && c != '-');
    if (c == '-') {
        sign = true;
        c = getchar();
    }
    do {
        x = x * 10 + c - '0';
        c = getchar();
    } while(isdigit(c));
    if (sign) x = -x;
}

template <typename T> void Write(T n) {
    if (n == 0) {
        putchar('0');
        putchar(' ');
        return;
    }
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    char c[30]; int k = 0;
    while (n) {
        c[++k] = n % 10 + '0';
        n /= 10;
    }
    for (int i = k; i >= 1; i--)
        putchar(c[i]);
    putchar(' ');

}

typedef long long LL;
const int N = 2005;
const int base = 1E9 + 7;

struct Edge {
    int u, v;
    LL w;
    bool mark;
    Edge (int _u = 0, int _v = 0, LL _w = 0, bool _mark = 0): u(_u), v(_v), w(_w), mark(_mark) {};
    bool operator < (const Edge &other) const {
        return w < other.w;
    }
};

struct DSU {
    int par[N];
    void Init() {
        memset(par, -1, sizeof(par));
    }
    int Root(int u) {
        if (par[u] < 0) return u;
        return par[u] = Root(par[u]);
    }
    bool Union(int x, int y) {
        x = Root(x); y = Root(y);
        if (x == y) return 0;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return 1;
    }
} DSU;

int n;
int x[N], y[N];
int b[N], c[N];
vector <Edge> E;

void Read_Input() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // LOCAL
    Read(n);
    FOR(i, 1, n) Read(x[i]), Read(y[i]);
    FOR(i, 1, n) Read(b[i]);
    FOR(i, 1, n) Read(c[i]);
}

void Build() {
    FOR(i, 1, n) FOR(j, 1, n) {
        if (i == j) continue;
        E.push_back(Edge(i, j, (LL)(c[i] + c[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))));
    }
    FOR(i, 1, n) E.push_back(Edge(0, i, b[i]));
    sort(E.begin(), E.end());
}

void Solve() {
    LL ans = 0;
    DSU.Init();
    REP(i, 0, E.size()) {
        int u = E[i].u, v = E[i].v;
        LL w = E[i].w;
        if (DSU.Union(u, v)) ans += w, E[i].mark = 1;
    }
    vector <int> state;
    vector <pair <int, int> > net;
    REP(i, 0, E.size()) if (E[i].mark) {
        if (E[i].u == 0) state.push_back(E[i].v);
            else net.push_back({E[i].u, E[i].v});
    }
    Write(ans); putchar('\n');
    Write(state.size()); putchar('\n');
    REP(i, 0, state.size()) Write(state[i]);
    putchar('\n'); Write(net.size()); putchar('\n');
    REP(i, 0, net.size()) Write(net[i].first), Write(net[i].second), putchar('\n');
}

int main() {
    Read_Input();
    Build();
    Solve();
    return 0;
}


