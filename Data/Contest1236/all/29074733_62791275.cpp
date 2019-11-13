#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9 + 7;

/* Retrieved from https://cp-algorithms.com/algebra/binary-exp.html */
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    clock_t begin_time = clock();

    long long n, m;
    cin >> n >> m;

    long long ans = binpow(binpow(2, m) - 1, n);

    // Print answer
    cout << ans << "\n";

    // Print exec time
    clock_t end_time = clock();
    double elapsed_secs = double(end_time - begin_time) / CLOCKS_PER_SEC;
    cerr << "Exec time: " << elapsed_secs << " s" << endl;
}
