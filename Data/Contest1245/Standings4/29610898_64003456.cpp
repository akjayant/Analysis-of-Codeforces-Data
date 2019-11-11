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
const int N = 5e4 + 10;
const int M = (1 << 10) + 10;
const int maxn = 2e3 + 10;
const int maxm = 4e3 + 10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 998244353;
const db eps = 1e-5;

int cnt[3];
char s[N];
char ans[N];

int main() {
#ifdef purple_bro
    freopen("in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;

    cin >> T;

    for (; T--;) {
        int a, b, c, n;

        cin >> n >> a >> b >> c >> s + 1;

        for (int i = 0; i < 3; i++)
            cnt[i] = 0;

        for (int i = 1; i <= n; i++) {
            if (s[i] == 'R')
                cnt[0]++;
            else if (s[i] == 'P')
                cnt[1]++;
            else if (s[i] == 'S')
                cnt[2]++;
        }

        int sum = min(a, cnt[2]) + min(b, cnt[0]) + min(c, cnt[1]);

        if (sum * 2 >= n) {
            cout << "YES" << "\n";
            for (int i = 1; i <= n; i++)
                ans[i] = 0;
            for (int i = 1; i <= n; i++) {
                if (s[i] == 'R' && b) {
                    b--;
                    ans[i] = 'P';
                } else if (s[i] == 'P' && c) {
                    c--;
                    ans[i] = 'S';
                } else if (s[i] == 'S' && a) {
                    a--;
                    ans[i] = 'R';
                }
            }
            for (int i = 1; i <= n; i++) if (ans[i] == 0) {
                if (a) {
                    a--;
                    ans[i] = 'R';
                } else if (b) {
                    b--;
                    ans[i] = 'P';
                } else if (c) {
                    c--;
                    ans[i] = 'S';
                }
            }
            ans[n + 1] = '\0';
            cout << ans + 1 << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }


    return 0;
}
