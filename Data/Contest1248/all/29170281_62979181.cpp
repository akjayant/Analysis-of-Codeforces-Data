#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define N 100005
#define M 100005
#define INF 0x3f3f3f3f
#define mk(x) (1<<x) // be conscious if mask x exceeds int
#define sz(x) ((int)x.size())
#define upperdiv(a,b) (a/b + (a%b>0))
#define mp(a,b) make_pair(a, b)
#define endl '\n'
#define lowbit(x) (x&-x)

using namespace std;
typedef long long ll;
typedef double db;

/** fast read **/
template <typename T>
inline void read(T &x) {
    x = 0; T fg = 1; char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') fg = -1;
        ch = getchar();
    }
    while (isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    x = fg * x;
}
template <typename T, typename... Args>
inline void read(T &x, Args &... args) { read(x), read(args...); }
template <typename T>
inline void write(T x) {
    int len = 0; char c[21]; if (x < 0) putchar('-'), x = -x;
    do{++len; c[len] = x%10 + '0';} while (x /= 10);
    for (int i = len; i >= 1; i--) putchar(c[i]);
}
template <typename T, typename... Args>
inline void write(T x, Args ... args) { write(x), write(args...); }

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        read(n);
        int pji = 0, pou = 0;
        int qji = 0, qou = 0;
        for (int i = 1; i <= n; i++) {
            int p; read(p);
            if (p&1)
                pji++;
            else
                pou++;
        }
        read(m);
        for (int i = 1; i <= m; i++) {
            int q; read(q);
            if (q&1)
                qji++;
            else
                qou++;
        }
        ll ans = 1LL * qji * pji;
        ans += 1LL * qou * pou;
        cout << ans << endl;
    }
    return 0;
}
