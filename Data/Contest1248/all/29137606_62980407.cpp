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

int n, a[maxn];
ll cnt1, cnt2;

int main() {
    cin >> n;
    inc(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    inc(i, 1, n / 2) cnt1 += a[i];
    inc(i, n / 2 + 1, n) cnt2 += a[i];
    cout << cnt1 * cnt1 + cnt2 * cnt2;
}