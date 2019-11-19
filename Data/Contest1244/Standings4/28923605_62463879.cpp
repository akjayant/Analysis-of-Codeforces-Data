#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using ll = long long;
using vll = vector<ll>;
#define szof(a) (int)a.size()
#define allof(a) a.begin(), a.end()
#define f first
#define s second

int main() {
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c, d, k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        int pen = (a + c - 1) / c;
        int pencil = (b + d - 1) / d;
        if (pen + pencil <= k) {
            printf("%d %d\n", pen, pencil);
        } else {
            printf("-1\n");
        }
    }
}