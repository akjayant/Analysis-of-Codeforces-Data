#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, odd = 0, even = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x & 1) odd++; else even++;
        }
        ll ans = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x & 1) ans += odd;
            else ans += even;
        }
        cout << ans << endl;
    }
}
