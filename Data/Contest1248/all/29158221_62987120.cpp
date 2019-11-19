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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stable_sort(a.begin(), a.end());
    int p = 0, q = 0;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            p += a[i];
        }
        else {
            q += a[i];
        }
    }
    cout << p * p + q * q << endl;
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
