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

ll a[N];
int main()
{
    int n; read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
    }
    sort(a+1, a+1+n);
    ll h = 0, w = 0;
    for (int i = 1; i <= n/2; i++) {
        h += a[i];
        w += a[n-i+1];
    }
    if (n&1) {
        w += a[n/2+1];
    }
    ll ans = h*h + w*w;
    cout << ans << endl;
    return 0;
}
