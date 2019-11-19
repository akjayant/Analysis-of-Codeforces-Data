#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<long long> len(2);
    sort(A.begin(), A.end());
    rep(i, N) {
        if(i < N / 2) len[0] += A[i];
        else len[1] += A[i];
    }
    long long ans = len[0] * len[0] + len[1] * len[1];
    cout << ans << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
