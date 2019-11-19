#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define reg register
#define rep(i, a, b) for (reg int i = (a), i##end = (b); i <= i##end; ++i)
#define dep(i, a, b) for (reg int i = (a), i##end = (b); i >= i##end; --i)

template <typename _typer> inline _typer read() {
    _typer init = 0;
    char ch = getchar(), k = 0;
    for ( ; !isdigit(ch); ch = getchar()) k = (ch == '-');
    for ( ; isdigit(ch); ch = getchar())
        init = (init << 3) + (init << 1) + (ch ^ 48);
    return k ? -init : init;
}
const ll N = 100005, INF = 1e9;

/*******************************************************************************
 *
 *
 *
 ******************************************************************************/


int n, A[N], cnt[N], Ans;
ll m;


int main() {
    n = read<int>(), m = read<ll>();
    rep (i, 1, n) A[i] = read<int>();

    sort(A + 1, A + n + 1);

    int tot = 0;
    rep (i, 1, n) if (A[i] != A[tot]) {
        A[++tot] = A[i];
        cnt[tot] = 1;
    } else ++cnt[tot];

    Ans = A[tot] - A[1];
    int curl = 1, curr = tot;
    while (m > 0 && curl < curr) {
        if (Ans == 0) return puts("0"), 0;
        if (cnt[curl] < cnt[curr]) {
            int t = A[curl + 1] - A[curl];
            if (m < 1ll * t * cnt[curl]) {
                Ans -= m / cnt[curl];
                m = 0;
            } else {
                m -= 1ll * t * cnt[curl], Ans -= t;
                ++curl, cnt[curl] += cnt[curl - 1];
            }
        } else {
            int t = A[curr] - A[curr - 1];
            if (m < 1ll * t * cnt[curr]) {
                Ans -= m / cnt[curr];
                m = 0;
            } else {
                m -= 1ll * t * cnt[curr], Ans -= t;
                --curr, cnt[curr] += cnt[curr + 1];
            }
        }
    }

    printf("%d\n", Ans);
    return 0;
}

