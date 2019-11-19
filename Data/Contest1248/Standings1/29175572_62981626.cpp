#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e6;

int main() {
    ios::sync_with_stdio(false);
    int cas;
    cin >> cas;
    while(cas --) {
        int n, m;
        int has[2][2] = {0};
        cin >> n;
        for(int i = 1;i <= n;i ++) {
            int t;
            cin >> t;
            has[0][t & 1] ++;
        }
        cin >> m;
        for(int i = 1;i <= m;i ++) {
            int t;
            cin >> t;
            has[1][t & 1] ++;
        }
        LL ans = 0;
        ans += 1ll * has[0][0] * has[1][0] + 1ll * has[0][1] * has[1][1];
        cout << ans << endl;
    }
    return 0;
}