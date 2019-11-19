#include <iostream> // C++ I/O
#include <string>   // C++ string
#include <fstream>  // File I/O
#include <sstream>  // String stream I/O
#include <iomanip>  // C++ I/O manipulator

#include <cstdlib> // C library
#include <cstdio>  // C I/O
#include <ctime>   // C time
#include <cmath>   // Math library
#include <cstring> // C strings

#include <vector>    // Vector
#include <queue>     // Queue
#include <stack>     // Stack
#include <map>       // Map
#include <set>       // Set
#include <bitset>    // Bitset
#include <algorithm> // Algorithms

using namespace std;

#define INF 0x3f3f3f3f
#define EPS 1e-8

typedef long long ll;
typedef unsigned long long ull;

#define memclr(_var) memset(_var, 0, sizeof(_var))
#define maximize(_var, _cur) _var = max(_var, _cur)
#define minimize(_var, _cur) _var = min(_var, _cur)
#define reps(_var, _begin, _end, _step) for (int _var = (_begin); _var <= (_end); _var += (_step))
#define reps_(_var, _end, _begin, _step) for (int _var = (_end); _var >= (_begin); _var -= (_step))
#define rep(_var, _begin, _end) reps(_var, _begin, _end, 1)
#define rep_(_var, _end, _begin) reps_(_var, _end, _begin, 1)

inline int read()
{
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

const int MAXN = 2010, MAXM = (MAXN * MAXN) << 1;
ll xs[MAXN], ys[MAXN];
ll c[MAXN], k[MAXN];

vector<int> res1;
typedef pair<int, int> pii;
vector<pii> res2;

struct dsu
{
    int nd[MAXN];
    void init(int n)
    {
        for (int i = 0; i <= n; i++)
            nd[i] = i;
    }
    int find(int x)
    {
        return nd[x] == x ? x : nd[x] = find(nd[x]);
    }
    void merge(int a, int b)
    {
        nd[find(a)] = find(b);
    }
    bool connected(int a, int b)
    {
        return find(a) == find(b);
    }
};

int tot = 0;

struct edge
{
    int u, v;
    ll w;
} e[MAXM];

void add_edge(int x, int y, ll w)
{
    tot++;
    e[tot].u = x;
    e[tot].v = y;
    e[tot].w = w;
}

bool cmp(const edge &a, const edge &b)
{
    return a.w < b.w;
}

ll dis(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = read();

    dsu d;
    d.init(n + 1);

    rep (i, 1, n)
        xs[i] = read(), ys[i] = read();

    rep (i, 1, n)
        c[i] = read();

    rep (i, 1, n)
        k[i] = read();
    
    rep (i, 1, n)
        add_edge(n + 1, i, c[i]);
    
    rep (i, 1, n)
        rep (j, i + 1, n)
        {
            ll cost = (k[i] + k[j]) * dis(xs[i], ys[i], xs[j], ys[j]);
            add_edge(i, j, cost);
        }

    sort(e + 1, e + tot + 1, cmp);

    ll res = 0;
    rep (i, 1, tot)
    {
        int u = e[i].u, v = e[i].v;
        ll w = e[i].w;
        if (d.connected(u, v))
            continue;
        d.merge(u, v);
        res += w;
        if (u == n + 1)
            res1.push_back(v);
        else
            res2.push_back(pii{u, v});
    }

    printf("%lld\n", res);
    printf("%d\n", (int)res1.size());
    for (auto it : res1)
        printf("%d ", it);
    putchar('\n');
    printf("%d\n", (int)res2.size());
    for (auto it : res2)
        printf("%d %d\n", it.first, it.second); 

    return 0;
}