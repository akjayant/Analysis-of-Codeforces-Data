#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;

const int INF = 1 << 30;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    sort(all(A));
    reverse(all(A));
    int ans = 0;
    int min_a = INF;
    rep(i, 0, N) {
        min_a = min(min_a, A[i]);
        ans = max(ans, min(min_a, i + 1));
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    rep(i, 0, T) solve();
    return 0;
}