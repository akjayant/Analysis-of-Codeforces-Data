
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

#define X first
#define Y second
#define A(x) get<0>(x)
#define B(x) get<1>(x)
#define C(x) get<2>(x)
#define D(x) get<3>(x)

mt19937 gen(228);

#ifdef DEBUG
#define dbg(x) cout << "[dbg " << __LINE__ << "] " << x << endl
#else
#define dbg(x) ((void)0)
#endif

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> pieces(n);

    for (int i = 0; i < n; i++) {
        cin >> pieces[i];
    }

    sort(all(pieces));

    ll ans = 0;

    ll cur_x = 0, cur_y = 0;
    if (n % 2 != 0) {
        for (int i = 0; i < n / 2; i++) {
            cur_x += pieces[i];
        }
        for (int i = n / 2 + 1; i < n; i++) {
            cur_y += pieces[i];
        }
        ans = max(ans, max((cur_x + pieces[n / 2]) * 1LL * (cur_x + pieces[n / 2]) + cur_y * 1LL * cur_y, cur_x * 1LL * cur_x + (cur_y + pieces[n / 2]) * 1LL * (cur_y + pieces[n / 2])));
    } else {
        for (int i = 0; i < n / 2; i++) {
            cur_x += pieces[i];
        }
        for (int i = n / 2; i < n; i++) {
            cur_y += pieces[i];
        }
        ans = max(ans, cur_x * 1LL * cur_x + cur_y * 1LL * cur_y);
    }

    cout << ans << "\n";

    return 0;
}
