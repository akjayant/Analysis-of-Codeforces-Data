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
const int lim = 100;
char s[lim], t[lim];
int cnt[300];
int main() {
    int k, n;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        loe(i, 'a', 'z') cnt[i] = 0;
        lo(i, 0, n) cnt[s[i] = gc()]++;
        lo(i, 0, n) cnt[t[i] = gc()]++;
        bool flag = false;
        loe(i, 'a', 'z') if (cnt[i] & 1) {
            flag = true;
            break;
        }
        if (flag) {
            printf("No\n");
            continue;
        }
        vector<pair<int, int> > dat;
        lo(i, 0, n) {
            if (s[i] != t[i]) {
                bool f = true;
                lo(j, 0, n) {
                    if (j != i && t[j] == t[i] && t[j] != s[j]) {
                        dat.pb(mk(i, j));
                        sw(s[i], t[j]);
                        f = false;
                        break;
                    }
                }
                if (f) {
                    lo(k, i + 1, n) {
                        if (s[k] == t[i]) {
                            dat.pb(mk(i, i));
                            dat.pb(mk(k, i));
                            sw(s[i], t[i]);
                            sw(s[k], t[i]);
                            break;
                        }
                    }
                }
            }
        }
        bool f = true;
        lo(i, 0, n) {
            if (s[i] != t[i]) {
                f = false;
                break;
            }
        }
        if (dat.size() > 2 * n) f = false;
        if (f) {
            printf("Yes\n");
            printf("%d\n", (int)dat.size());
            lo(i, 0, dat.size()) {
                printf("%d %d\n", dat[i].first + 1, dat[i].second + 1);
            }
        } else {
            printf("No\n");
        }
    }
    return 0;
}
