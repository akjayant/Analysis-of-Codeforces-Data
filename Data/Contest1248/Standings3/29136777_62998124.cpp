#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int calc(int n, int m) {
    vector<int> fib(N, 0);
    fib[1] = 2;
    fib[2] = 4;
    for (int i = 3; i < N; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    int res = fib[n];
    vector<int> tmp(N, 0);
    tmp[0] = 0;
    tmp[1] = 2;
    tmp[2] = 2;
    for (int i = 3; i < N; i++)
        tmp[i] = (tmp[i - 1] + tmp[i - 2]) % MOD;
    int sm = 0;
    for (int i = 0; i < m; i++)
        sm = (sm + tmp[i]) % MOD;
    res = (res + sm) % MOD;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    cout << calc(n, m);
}