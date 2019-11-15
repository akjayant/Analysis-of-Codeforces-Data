#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 100005;

char s[N];
int f[N];
int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            puts("0");
            return 0;
        }
    }
    LL ans = 1;
    f[1] = 1, f[0] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    LL cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            if (s[i - 1] == 'n' || s[i - 1] == 'u') {
                ans = ans * f[cnt] % mod;
            }
            cnt = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
