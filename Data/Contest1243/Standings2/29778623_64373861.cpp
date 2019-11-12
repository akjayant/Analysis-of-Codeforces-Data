#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll maxn = 1e5 + 10;

void yn(int x) {
    if (x) cout << "Yes" << endl;
    else cout << "No" << endl;
}


ll a[maxn];

int main() {

    ll t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
             ans = max(ans,min(a[i],n-i+1));

        }
        cout << ans << endl;
    }

    return 0;
}