
#include <iostream>  // C++ I/O
#include <fstream>  // File I/O
#include <sstream>  // String stream I/O
#include <iomanip>  // C++ I/O manipulator

#include <cstdlib>  // C library
#include <cstdio>  // C I/O
#include <ctime>  // C time
#include <cmath>  // Math library
#include <cstring>  // C strings

#include <vector>  // Vector
#include <queue>  // Queue
#include <stack>  // Stack
#include <map>  // Map
#include <set>  // Set
#include <algorithm>  // Algorithms

using namespace std;

#define reps(_var,_begin,_end,_step)  for (int _var = (_begin);  \
    _var <= (_end); _var += (_step))
#define reps_(_var,_end,_begin,_step)  for (int _var = (_end);  \
    _var >= (_begin); _var -= (_step))
#define rep(_var,_begin,_end)  reps(_var, _begin, _end, 1)
#define rep_(_var,_end,_begin)  reps_(_var, _end, _begin, 1)
#define minimize(_var,_targ)  _var = min(_var, _targ)
#define maximize(_var,_targ)  _var = max(_var, _targ)

typedef unsigned long long ull;
typedef long long lli, ll;
typedef double llf;

template <typename typ>
void memclr(typ p) {
    memset(p, 0, sizeof(p)); }
template <typename typ>
void memclr(typ arr[], int n) {
    memset(arr, 0, sizeof(arr[0]) * (n + 1)); }
template <typename typ, int dim>
void memclr(typ arr[][dim], int n, int m) {
    rep(i, 0, n) memset(arr[i], 0, sizeof(arr[i][0]) * (m + 1)); }

lli read(void)
{
    lli res = 0, sgn = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
        sgn = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9')
        res = res * 10 + ch - '0', ch = getchar();
    return res * sgn;
}

const int maxn = 2010;
const lli infinit = 0x007f7f7f7f7f7f7fll;

class Prim
{
public:
    lli dist[maxn][maxn];
    int n, vis[maxn], min_cost[maxn];
    vector<pair<int, int>> edges;
    void add_edge(int u, int v, lli len)
    {
        dist[u][v] = dist[v][u] = len;
        return ;
    }
    void join(int u, int v)
    {
        add_edge(u, v, 0);
        return ;
    }
    lli eval(void)
    {
        lli min_span = 0;
        rep(i, 1, n) {
            vis[i] = false;
            min_cost[i] = 1;
        }
        vis[1] = true;
        rep(i, 1, n) {
            int p = 0;
            rep(j, 1, n)
                if (!vis[j] && dist[min_cost[j]][j] < dist[min_cost[p]][p])
                    p = j;
            if (p == 0)
                break;
            min_span += dist[min_cost[p]][p];
            if (min_cost[p] < p)
                edges.push_back(make_pair(min_cost[p], p));
            else
                edges.push_back(make_pair(p, min_cost[p]));
            vis[p] = true;
            rep(j, 1, n)
                if (dist[p][j] < dist[min_cost[j]][j])
                    min_cost[j] = p;
        }
        return min_span;
    }
    void init(int n)
    {
        this->n = n;
        rep(i, 0, n)
            rep(j, 0, n)
                dist[i][j] = infinit;
        edges.clear();
        return ;
    }
} graph;

int n;
lli x[maxn], y[maxn];
lli c[maxn], k[maxn];

lli dist(int i, int j)
{
    lli dx = x[i] - x[j], dy = y[i] - y[j];
    if (dx < 0)
        dx = - dx;
    if (dy < 0)
        dy = - dy;
    return dx + dy;
}

int main(int argc, char** argv)
{
    scanf("%d", &n);
    rep(i, 1, n)
        scanf("%lld%lld", &x[i], &y[i]);
    rep(i, 1, n)
        scanf("%lld", &c[i]);
    rep(i, 1, n)
        scanf("%lld", &k[i]);
    // create graph
    graph.init(n + 1);
    rep(i, 1, n) {
        rep(j, i + 1, n)
            graph.add_edge(i, j, (k[i] + k[j]) * dist(i, j));
        graph.add_edge(i, n + 1, c[i]);
    }
    lli res = graph.eval();
    vector<int> stats;
    vector<pair<int, int>> links;
    for (auto pr : graph.edges) {
        if (pr.second == n + 1)
            stats.push_back(pr.first);
        else
            links.push_back(pr);
    }
    // real output
    sort(stats.begin(), stats.end());
    sort(links.begin(), links.end());
    printf("%lld\n", res);
    printf("%d\n", stats.size());
    for (auto p : stats)
        printf("%d ", p);
    printf("\n");
    printf("%d\n", links.size());
    for (auto pr : links)
        printf("%d %d\n", pr.first, pr.second);
    return 0;
}
