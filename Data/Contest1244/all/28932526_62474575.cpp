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
const ll N = 1005, INF = 1e9;

/*******************************************************************************
 *
 *
 *
 ******************************************************************************/


int main() {
    rep (ks, 1, read<int>()) {
        int n = read<int>();
        string s; cin >> s;
        int Ansl = 0, Ansr = 0, Ansm = n;
        dep (i, n, 1) if (s[i - 1] == '1') {
            Ansl = i * 2;
            break;
        }
        rep (i, 1, n) if (s[i - 1] == '1') {
            Ansr = (n - i + 1) * 2;
            break;
        }
        rep (i, 1, n) if (s[i - 1] == '1') ++Ansm;
        cout << max(Ansm, max(Ansl, Ansr)) << endl;
    }
    return 0;
}

