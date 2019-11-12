#include <bits/stdc++.h>
#define fi first
#define se second
using ll = long long;
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        int ans = 0;
        int i = 0;
        while(i < n && a[i++] > ans) ans += 1;
        cout << ans << '\n';
    }
}
