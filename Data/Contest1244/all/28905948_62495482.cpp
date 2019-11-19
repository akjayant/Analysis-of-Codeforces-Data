#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define int long long
#define ll long long
#define ins insert
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define ld long double
#define rsz resize
#define pii pair<int, int>

using namespace std;

mt19937 rnd(time(nullptr));

const long long INF = 1e18;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    int x = 0, y = n - 1;
    for (int i = 0; i < n; i++) {
        if (x == y) {
            cout << 0;
            return 0;
        }
        int d1 = a[x + 1] - a[x], d2 = a[y] - a[y - 1];
        if ((x + 1) < (n - y)) {
            if (k >= d1 * (x + 1)) {
                k -= d1 * (x + 1);
                x++;
                continue;
            }
            int cnt = min(x + 1, n - y);
            cout << max(0ll, a[y] - a[x] - (k / cnt));
            return 0;
        } else {
            if (k >= d2 * (n - y)) {
                k -= d2 * (n - y);
                y--;
                continue;
            }
            int cnt = min(x + 1, n - y);
            cout << max(0ll, a[y] - a[x] - (k / cnt));
            return 0;
        }
    }
    return 0;
}
