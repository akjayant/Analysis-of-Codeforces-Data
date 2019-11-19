#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    long long p = 1'000'000'007;
    vector<long long> fib(100'001);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= 100'000; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % p;
    }
    cout << 2 * (fib[n] + fib[m] - 1) % p << '\n';
    return 0;
}
