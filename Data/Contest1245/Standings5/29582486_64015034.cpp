#include <bits/stdc++.h>

#define lo(i, n, m) for (int i = n; i < m; i++)
#define loe(i, n, m) for (int i = n; i <= m; i++)
#define rlo(i, n, m) for (int i = n - 1; i >= m; i--)
#define rloe(i, n, m) for (int i = n; i >= m; i--)
#define pb push_back
#define mk make_pair
#define scd(x) scanf("%d", &x)
#define scs(x) scanf("%s", x)
#define sclf(x) scanf("%lf", &x)
#define scll(x) scanf("%lld", &x)
#define clr(a, b) memset((a), (b), sizeof(a))
typedef long long LL;
using namespace std;
// const int INF = 0x3f3f3f3f;
// const int INF = 0x7fffffff;
// const LL INF = 0x3f3f3f3f3f3f3f3f;
// const LL INF = 0x7fffffffffffffff;
const int NIL = -1;
template <class T>
inline T mx(T a, T b) {return a > b ? a : b;}
template <class T>
inline T mi(T a, T b) {return a < b ? a : b;}
template <class T>
inline void sw(T &a, T &b) {
    T t = a; a = b; b = t;
}
template <class T>
inline T mabs(T x) {return x < 0 ? -x : x;}
inline char gc() {
    char ret;
    while ((ret = getchar()) == ' ' || ret == '\n' || ret == '\t');
    return ret;
}
template <class T>
inline T sq(T x) {return x * x;}

const LL mod = 1e9 + 7;
const int lim = 1e5 + 10;
LL buf[lim];
inline LL mul(LL a, LL b) {
    return ((a % mod) * (b % mod)) % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string str;
    cin >> str;
    buf[0] = 1ll;
    buf[1] = 1, buf[2] = 2;
    loe(i, 3, str.size()) buf[i] = (buf[i - 1] + buf[i - 2]) % mod;
    LL ans = 1ll, uc = 0, nc = 0;
    bool flag = true;
    lo(i, 0, str.size()) {
        if (str[i] == 'u') {
            ++uc;
            if (nc) ans = mul(ans, buf[nc]);
            nc = 0ll;
        } else if (str[i] == 'n') {
            ++nc;
            if (uc) ans = mul(ans, buf[uc]);
            uc = 0ll;
        } else {
            if (str[i] == 'm' || str[i] == 'w') {
                flag = false;
                break;
            }
            if (uc) ans = mul(ans, buf[uc]);
            if (nc) ans = mul(ans, buf[nc]);
            uc = nc = 0ll;
        }
    }
    if (!flag) {
        cout << 0;
        return 0;
    }
    if (uc) ans = mul(ans, buf[uc]);
    if (nc) ans = mul(ans, buf[nc]);
    cout << ans;
    return 0;
}
