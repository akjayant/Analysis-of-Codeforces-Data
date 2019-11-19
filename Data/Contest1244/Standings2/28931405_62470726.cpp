#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr ll MOD = 1e9 + 7;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        int mi = INF, co = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                chmin(mi, i);
                chmin(mi, n - 1 - i);
                co++;
            }
        }
        ans = 2 * (n - mi);
        chmax(ans, n + co);
        cout << ans << endl;
    }
}