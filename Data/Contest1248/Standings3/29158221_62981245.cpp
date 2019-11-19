#include <bits/stdc++.h>

#define int long long
#define double long double
#define float double

using namespace std;

void flags() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(16);
    cerr.tie();
    cerr.setf(ios::fixed, ios::floatfield);
    cerr.precision(4);
    return;
}

void solution() {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        int p0 = 0, p1 = 0;
        for (int i = 0, p; i < n; i++) {
            cin >> p;
            if (p % 2 == 0) {
                p0++;
            }
            else {
                p1++;
            }
        }
        int m;
        cin >> m;
        int q0 = 0, q1 = 0;
        for (int i = 0, q; i < m; i++) {
            cin >> q;
            if (q % 2 == 0) {
                q0++;
            }
            else {
                q1++;
            }
        }
        //cerr << p0 << ' ' << p1 << ' ' << q0 << ' ' << q1 << endl;
        cout << p0 * q0 + p1 * q1 << endl;
    }
    return;
}

signed main() {
#ifdef pomodorcat
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    flags();
    solution();
#else
    flags();
    solution();
#endif
    return 0;
}
