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
    int t;
    cin >> t;
    for (int w = 0; w < t; w++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') continue;
            ans = max(ans, max(i + 1, n - i) * 2);
        }
        cout << ans << "\n";
    }
    return 0;
}
