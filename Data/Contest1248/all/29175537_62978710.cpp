#include <bits/stdc++.h>

using namespace std;

//#define Local

int main(void) {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
#ifdef Local
    freopen("test/input.in", "r", stdin);
    //freopen("../output.out", "w", stdout);
#endif // Local
    int t; cin >> t;
    while (t --) {
        int n, m;
        cin >> n;
        long long num0 = 0, num1 = 0, ans = 0;
        for (int i = 0; i < n; i ++) {
            int x; cin >> x;
            if (x & 1)  num1 ++;
            else    num0 ++;
        }
        cin >> m;
        for (int i = 0; i < m; i ++) {
            int x; cin >> x;
            if (x & 1)  ans += num1;
            else    ans += num0;
        }
        cout << ans << endl;
    }
    return 0;
}
