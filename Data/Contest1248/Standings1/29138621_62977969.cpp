// qdd on Oct 20, 2019

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, x;
    cin >> n;
    vector<int> A(2), B(2);
    for (int i = 0; i < n; i++) {
        cin >> x;
        A[x % 2]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        B[x % 2]++;
    }
    cout << (1LL * A[0] * B[0] + 1LL * A[1] * B[1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}