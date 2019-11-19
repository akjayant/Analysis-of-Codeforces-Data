#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define gc getchar
#define il inline
#define re register
#define LL long long
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    bool p = 0;
    char ch;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
const int MAXN = 3000;
const int MAXM = 4500005;
const LL INF = 0x3fffffffffffffff;
typedef pair<int, int> P;
P a[MAXN];
LL dis[MAXN][MAXN];
LL k[MAXN];
LL DIS[MAXN];
int frm[MAXN];
int vis[MAXN];
int S;
LL ans;
vector<int> ans1;
vector<P> ans2;
#define abs(x) (((x) < 0) ? -(x) : (x))
int main()
{
    int n;
    read(n);
    S = n + 1;
    for (int i = 1; i <= n; ++i)
        read(a[i].first), read(a[i].second);
    for (int i = 1; i <= n; ++i)
        read(DIS[i]), frm[i] = S;
    for (int i = 1; i <= n; ++i)
        read(k[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            dis[i][j] = dis[j][i] = (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second)) * 1ll * (k[i] + k[j]);
    for (int i = 1; i <= n; ++i)
    {
        int id = 0, mx;
        for (int j = 1; j <= n; ++j)
        {
            if (!vis[j])
            {
                if (!id || DIS[j] < mx)
                    mx = DIS[j], id = j;
            }
        }
        if (!id)
            break;
        vis[id] = 1;
        ans += mx;
        if (frm[id] == S)
            ans1.push_back(id);
        else
            ans2.push_back(P(frm[id], id));
        for (int j = 1; j <= n; ++j)
            if (dis[id][j] < DIS[j])
                DIS[j] = dis[id][j], frm[j] = id;
    }
    printf("%lld\n", ans);
    printf("%d\n", ans1.size());
    for (auto x : ans1)
        printf("%d ", x);
    printf("\n");
    printf("%d\n", ans2.size());
    for (auto x : ans2)
        printf("%d %d\n", x.first, x.second);
    return 0;
}