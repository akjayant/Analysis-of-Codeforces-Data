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
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = -1, y = -1;
        for (int i = 0; i <= k; i++) {
            int j = k - i;
            if (i * c >= a && j * d >= b) {
                x = i, y = j;
                break;
            }
        }
        if (x == -1) {
            cout << -1 << endl;
        } else {
            cout << x << " " << y << endl;
        }
    }
}