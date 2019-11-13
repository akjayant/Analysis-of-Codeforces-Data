#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define debug(a) cout << #a": " << a << endl;
#define mst(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()
#define lc rt << 1
#define rc rt << 1 | 1
#define X first
#define Y second
inline int lowbit(int x) { return x & -x; }
typedef long long ll;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef pair<int*, int> pii;
typedef pair<int, LL> pil;
const int N = 1e5 + 10;
const int M = (1 << 10) + 10;
const int maxn = 2e3 + 10;
const int maxm = 4e3 + 10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const db eps = 1e-5;

char s[N];
int f[N];

int main() {
#ifdef purple_bro
    freopen("in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    f[1] = f[2] = 1;

    for (int i = 2; i < N; i++)
        f[i] = (f[i - 1] + f[i - 2]) % mod;

    cin >> s + 1;

    int len = strlen(s + 1);

    int ans = 1;

    for (int i = 1; i <= len; i++) if (s[i] == 'm' || s[i] == 'w')
        ans = 0;

    int now = 0;

    for (int i = 1; i <= len; i++) {
        if (s[i] == 'u')
            now++;
        else {
            if (now > 1) {
                ans = 1LL * ans * f[now + 1] % mod;
            }
            now = 0;
        }
    }

    if (now > 1)
        ans = 1LL * ans * f[now + 1] % mod;

    now = 0;

    for (int i = 1; i <= len; i++) {
        if (s[i] == 'n')
            now++;
        else {
            if (now > 1) {
                ans = 1LL * ans * f[now + 1] % mod;
            }
            now = 0;
        }
    }

    if (now > 1)
        ans = 1LL * ans * f[now + 1] % mod;

    cout << ans << "\n";

    return 0;
}
