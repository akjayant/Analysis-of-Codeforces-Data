#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define inc(i, l, r) for (int i = l; i <= r; i++)
#define dec(i, l, r) for (int i = l; i >= r; i--)
#define mes(x, k) memset(x, k, sizeof(x))
#define bug() printf("LINE: %d.\n", __LINE__)
const int maxn = 1e6 + 5;

int t, n, m;
ll cnt1, cnt2, x;

int main() {
    cin >> t;
    while (t--) {
        cnt1 = cnt2 = 0;
        cin >> n;
        inc(i, 0, n - 1) {
            cin >> x;
            if (x & 1) cnt1++;
        }
        cin >> m;
        inc(i, 0, m - 1) {
            cin >> x;
            if (x & 1) cnt2++;
        }
        cout << cnt1 * cnt2 + (n - cnt1) * (m - cnt2) << "\n";
    }
}