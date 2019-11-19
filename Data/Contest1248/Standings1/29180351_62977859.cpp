#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n;
        int aocnt = 0, aecnt = 0;
        int bocnt = 0, becnt = 0;
        for(int i = 0; i < n; ++i) {
            int p;
            cin >> p;
            if(p&1) ++aocnt;
            else ++aecnt;
        }
        cin >> m;
        for(int i = 0; i < m; ++i) {
            int q;
            cin >> q;
            if(q&1) ++bocnt;
            else ++becnt;
        }
        long long ans = 1ll * aocnt * bocnt + 1ll * aecnt * becnt;
        cout << ans << '\n';
    }
    return 0;
}
