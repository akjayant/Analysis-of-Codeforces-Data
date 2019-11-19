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

int q, n;
char stairs[1005];
int main() {
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#endif
    scanf("%d", &q);
    while (q--) {
        scanf("%d %s", &n, stairs + 1);
        int l;
        for (l = 1; l <= n; ++l)
            if (stairs[l] == '1') break;
        int r;
        for (r = n; r >= 1; --r)
            if (stairs[r] == '1') break;
        int ans;
        if (l != n + 1) {
            ans = max(2 * r, 2 * (n - l + 1));
        } else {
            ans = n;
        }
        printf("%d\n", ans);
    }
}