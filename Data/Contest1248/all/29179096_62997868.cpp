#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
const long long MOD = 1000000007;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<long long> F(100010);
    F[1] = 1;
    F[2] = 2;
    for(int i = 3; i <= 100003; ++i) F[i] = (F[i-1] + F[i-2]) % MOD;
    long long f = F[N] + F[M] - 1;
    if(f < 0) f += MOD;
    long long ans = f * 2 % MOD;
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
