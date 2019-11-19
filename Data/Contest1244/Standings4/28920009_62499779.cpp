#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

const ll INF = 1e18 + 10;
const ll N = 1e6 + 10;

void solve() {
    ll n, p, w, d;
    cin >> n >> p >> w >> d;

    ll x = 0;
    ll timer = 0;
    for(ll i = p / w; i >= 0; i--) {
        timer++;
        if (timer > N) {
            break;
        }

        if ((p - w * i) % d == 0) {
            x = i;
            break;
        }
    }

    //cout << x << "\n";

    ll y = (p - (x * w)) / d;

    if (x + y <= n && x * w + y * d == p) {
        cout << x << " " << y << " " << n - x - y << "\n";
    }
    else {
        cout << "-1\n";
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t = 1;
    //cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
/*
*/
