#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

void solve() {
    int N; cin >> N;
    long long ans = 0;
    vector<long long> cnt(2);
    rep(i, N) {
        int a; cin >> a;
        cnt[a % 2]++;
    }
    int M; cin >> M;
    rep(i, M) {
        int a; cin >> a;
        ans += cnt[a % 2];
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
