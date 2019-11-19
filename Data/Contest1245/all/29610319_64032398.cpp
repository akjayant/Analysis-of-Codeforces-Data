#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000005;

#define x first
#define y second
typedef pair<int, int> ii;
typedef pair<int64_t, ii> iii;

iii e[maxn];
ii Y[maxn], x[maxn];

int n, sl = 0;
int64_t ans = 0;
int tram = 0, day = 0, X[maxn], k[maxn], lt[maxn];

int dis(int i, int j) {
    return abs(x[i].x - x[j].x) + abs(x[i].y - x[j].y);
}

int Find(int u) {
    if(lt[u] == u) return u;
    return lt[u] = Find(lt[u]);
}
void Solve() {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i)
            scanf("%d %d", &x[i].x, &x[i].y);
        for(int i = 1; i <= n; ++ i) {
            int u;
            scanf("%d", &u);
            e[++sl] = iii(u, ii(0, i));
        }
        for(int i = 1; i <= n; ++ i)
            scanf("%d", &k[i]);
        for(int i = 1; i <= n; ++ i)
        for(int j = 1; j < i; ++ j)
            e[++sl] = iii(1ll*(k[i]+k[j])*dis(i, j), ii(i, j));

        sort(e + 1, e + sl + 1);
        for(int i = 0; i <= n; ++ i) lt[i] = i;
        for(int i = 1; i <= sl; ++ i) {
            int u = e[i].y.x, v = e[i].y.y;
            if(u > v) swap(u, v);
            int a = Find(u), b = Find(v);
            if(a != b) {
                lt[a] = b;
                ans += 1ll*e[i].x;
                if(!u) X[++tram] = v;
                else Y[++day] = ii(u, v);
            }
        }

        printf("%I64d\n", ans);
        printf("%d\n", tram);
        for(int i = 1; i <= tram; ++ i) printf("%d ", X[i]);
        printf("\n%d\n", day);
        for(int i = 1; i <= day; ++ i) {
            printf("%d %d\n", Y[i].x, Y[i].y);
        }
}

#define task "main"
int main() {
        //freopen(task".inp","r",stdin);
        //freopen(task".out","w",stdout);
        Solve();
}
