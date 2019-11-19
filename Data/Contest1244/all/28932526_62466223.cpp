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
const ll N = 0, INF = 1e9;

/*******************************************************************************
 *
 *
 *
 ******************************************************************************/


int a, b, c, d, k;

int main() {
    rep (ks, 1, read<int>()) {
        cin >> a >> b >> c >> d >> k;
        int Ansx = -1;
        rep (x, 0, k) {
            int sx = x * c, sy = (k - x) * d;
            if (sx >= a && sy >= b) {
                Ansx = x;
                break;
            }
        }
        if (Ansx == -1) puts("-1");
        else cout << Ansx << " " << k - Ansx << endl;
    }
    return 0;
}

