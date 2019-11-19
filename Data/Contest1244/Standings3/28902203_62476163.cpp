#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll ans[] = {0, 0, 0};
    bool ok = false;
    for (ll i = 0; i < w; i++)
        if ((d * i) % w == p % w && i * d <= p) {
            if (i + (p - d * i) / w <= n) {
                ans[0] = (p - d * i) / w;
                ans[1] = i;
                ans[2] = n - ans[1] - ans[0];
                ok = true;
                break;
            }
        }
    if (ok)
        cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    else
        cout << "-1\n";
    return 0;
}