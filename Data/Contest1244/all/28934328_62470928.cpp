#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int n;
        cin >> n;
        int minit = 10000, maxit = -1;
        for (int i = 0; i < n; i++) {
            char x;
            cin >> x;
            if (x == '1') {
                if (minit == 10000) minit = i;
                maxit = i;
            }
        }
        if (maxit == -1) {
            cout << n << endl;
        }
        else {
            int a = minit + 1;
            int b = maxit - minit;
            int c = n - a - b;
            int ans = max(2 * a, 2 * (c + 1));
            ans = max(ans, n + 1);
            ans = max(ans, a + 1 + 2 * b);
            ans = max(ans, c + 1 + 1 + 2 * b);
            if (maxit != minit) {
                ans = max(ans, n + 2);
            }
            ans = max(ans, (a + b) * 2);
            ans = max(ans, (c + b + 1) * 2);
            cout << ans << endl;
        }
    }
    return 0;
}
