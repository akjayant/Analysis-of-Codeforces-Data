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
    const int MOD = 1e9 + 7;
    int ans = 0;
    for (int t = 0; t < 2; t++) {
        int n;
        cin >> n;
        if (n == 1) {
            ans = (ans + 2) % MOD;
            continue;
        }
        vector <int> bb(n), bw(n), wb(n), ww(n);
        bb[0] = 1;
        bw[0] = 1;
        wb[0] = 1;
        ww[0] = 1;
        //cerr << "1\t1\t1\t1" << endl;
        for (int i = 1; i < n - 1; i++) {
            bb[i] = (wb[i - 1]) % MOD;
            bw[i] = (bb[i - 1] + wb[i - 1]) % MOD;
            wb[i] = (bw[i - 1] + ww[i - 1]) % MOD;
            ww[i] = (bw[i - 1]) % MOD;
            //cerr << bb[i] << '\t' << bw[i] << '\t' << wb[i] << '\t' << ww[i] << endl;
        }
        //cerr << bb[n - 2] + bw[n - 2] + wb[n - 2] + ww[n - 2] << endl;
        ans = (ans + bb[n - 2] + bw[n - 2] + wb[n - 2] + ww[n - 2]) % MOD;
    }
    cout << (ans - 2 + MOD) % MOD << endl;
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
