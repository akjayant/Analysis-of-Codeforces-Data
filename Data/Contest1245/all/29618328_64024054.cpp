#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
#define cases(t) for (int cas = 1; cas <= int(t); ++cas)
typedef long long ll;
typedef double db;
using namespace std;

#ifdef NO_ONLINE_JUDGE
#define LOG(args...) do { cout << #args << " -> "; err(args); } while (0)
void err() { cout << endl; }
template<typename T, typename... Args> void err(T a, Args... args) { cout << a << ' '; err(args...); }
#else
#define LOG(...)
#endif

const int N = 2005;
const int M = N * N;
int n, m;
int x[N], y[N], c[N], k[N], f[N];
struct edge {
    int u, v;
    ll w;
    bool operator<(const edge &t) const { return w < t.w; }
} e[M];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
    ll ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)	scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= n; ++i)	scanf("%d", &c[i]), ans += c[i];
    for (int i = 1; i <= n; ++i)	scanf("%d", &k[i]);
    for (int i = 1; i <= n; ++i)	f[i] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            ll w = (ll)(k[i] + k[j]) * (ll)(abs(x[i] - x[j]) + abs(y[i] - y[j]));
            e[m++] = {i, j, w};
        }
    }
    sort(e, e + m);
    vector<int> power;
    vector<pair<int, int>> p;
    for (int i = 0; i < m; ++i) {
        int fx = find(e[i].u);
        int fy = find(e[i].v);
        if (fx == fy)	continue;
        if (c[fx] + c[fy] < min(c[fx], c[fy]) + e[i].w)	continue;
        if (c[fx] < c[fy]) {
            f[fy] = fx;
        } else {
            f[fx] = fy;
        }
        p.push_back({e[i].u, e[i].v});
        ans = ans - max(c[fx], c[fy]) + e[i].w;
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; ++i)	if (f[i] == i)	power.push_back(i);
    printf("%d\n", power.size());
    for (auto v : power)	printf("%d ", v);
    puts("");
    printf("%d\n", p.size());
    for (auto it : p)	printf("%d %d\n", it.first, it.second);
    return 0;
}