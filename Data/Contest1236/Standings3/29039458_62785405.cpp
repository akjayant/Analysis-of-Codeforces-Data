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

int t, n, a[4];

int main() {
    cin >> t;
    while (t--) {
        inc(i, 1, 3) cin >> a[i];
        int cnt = min(a[3] / 2, a[2]);
        a[2] -= cnt;
        cnt += min(a[2] / 2, a[1]);
        cout << cnt * 3 << "\n";
    }
}