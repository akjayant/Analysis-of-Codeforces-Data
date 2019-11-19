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
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    int ans = INF, x = n;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                ans = min(i, ans);
                x /= i;
            }
            break;
        }
    }
    if (ans == INF) {
        cout << n;
        return 0;
    }
    if (x != 1) {
        cout << 1;
        return 0;
    }
    cout << ans;
    return 0;
}
