
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 1e2;
int ts, n, a, b, c, dp[nsz + 5][nsz + 5][nsz + 5], pre[nsz + 5][nsz + 5][nsz + 5];
string s, ans;

char inline to(int id) {
    return (id == 0) ? 'R' : ((id == 1) ? 'P' : 'S');
}

void inline upd(int i, int j, int k, int b, int p) {
    if (dp[i][j][k] < b) {
        dp[i][j][k] = b;
        pre[i][j][k] = p;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> ts;
    cont (cs, ts) {
        cin >> n >> a >> b >> c >> s;
        n = (a + b + c);
        s = ' ' + s;
        ans.clear();
        circ (i, 0, a) {
            circ (j, 0, b) {
                circ (k, 0, c) {
                    dp[i][j][k] = -1;
                    pre[i][j][k] = -1;
                }
            }
        }
        dp[0][0][0] = 0;
        circ (i, 0, a) {
            circ (j, 0, b) {
                circ (k, 0, c) {
                    int val = dp[i][j][k], cnt = i + j + k + 1;
                    if (i + 1 <= a) {
                        upd(i + 1, j, k, val + (s[cnt] == 'S'), 0);
                    }
                    if (j + 1 <= b) {
                        upd(i, j + 1, k, val + (s[cnt] == 'R'), 1);
                    }
                    if (k + 1 <= c) {
                        upd(i, j, k + 1, val + (s[cnt] == 'P'), 2);
                    }
                }
            }
        }
        if (dp[a][b][c] >= (n - 1) / 2 + 1) {
            cout << "YES" << ln;
            int i = a, j = b, k = c;
            for (; i + j + k;) {
                int p = pre[i][j][k];
                ans += to(p);
                i -= p == 0;
                j -= p == 1;
                k -= p == 2;
            }
            reverse(all(ans));
            cout << ans << ln;
        } else {
            cout << "NO" << ln;
        }
    }
}