#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 100005;

char ans[202];
int main() {
    int _;
    cin >> _;
    while (_--) {
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        int t = (n + 1) / 2;
        int cnt = 0;
        memset(ans, 0, sizeof ans);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                if (b > 0) {
                    b--;
                    cnt++;
                    ans[i] = 'P';
                }
            } else if (s[i] == 'P') {
                if (c > 0) {
                    c--;
                    cnt++;
                    ans[i] = 'S';
                }

            } else if (s[i] == 'S') {
                if (a > 0) {
                    a--;
                    cnt++;
                    ans[i] = 'R';
                }
            }
        }

        puts(cnt >= t ? "YES" : "NO");
        if (cnt >= t) {
            for (int i = 0; i < n; i++) {
                if (ans[i] == 0) {
                    if (a > 0) {
                        ans[i] = 'R';
                        a--;
                    } else if (b > 0) {
                        ans[i] = 'P';
                        b--;
                    } else {
                        ans[i] = 'S';
                        c--;
                    }
                }
            }
            puts(ans);
        }
    }
    return 0;
}
