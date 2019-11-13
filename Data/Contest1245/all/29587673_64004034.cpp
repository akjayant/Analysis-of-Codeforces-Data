#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define F(i, n) for(int i = 0; i < n; ++i)

int32_t main() {
    ios_base::sync_with_stdio(false);
    int Q; cin >> Q;
    while (Q --> 0) {
        int n, a, b, c; cin >> n >> a >> b >> c;
        string ans(n, '0');
        F(i, n) {
            char ch;
            cin >> ch;
            if (ch == 'R' && b) {
                --b;
                ans[i] = 'P';
            }
            if (ch == 'S' && a) {
                --a;
                ans[i] = 'R';
            }
            if (ch == 'P' && c) {
                --c;
                ans[i] = 'S';
            }
        }

        int cnt = n - a - b - c;
        if (n % 2) ++ n;
        F(i, n) {
            if(ans[i] == '0') {
                if(a) {
                    -- a;
                    ans[i] = 'R';
                } else
                if(b) {
                    -- b;
                    ans[i] = 'P';
                } else
                if(c) {
                    -- c;
                    ans[i] = 'S';
                }
            }
        }
        if (cnt >= n / 2) {
            cout << "YES\n" << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
