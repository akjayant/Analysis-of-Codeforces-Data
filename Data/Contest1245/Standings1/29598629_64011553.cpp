
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 1e5, mod = 1e9 + 7;
int n, dp[nsz + 5];
string s;

void inline upd(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    n = (int) s.size();
    s = ' ' + s;
    dp[0] = 1;
    cont (i, n) {
        upd(dp[i], dp[i - 1]);
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0 << ln;
            return 0;
        }
        if ((s[i] == 'u' && s[i - 1] == 'u') || (s[i] == 'n' && s[i - 1] == 'n')) {
            upd(dp[i], dp[i - 2]);
        }
    }
    cout << dp[n] << ln;
}