
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

constexpr ll MOD = 1'000'000'007;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a_even = 0, a_odd = 0, b_even = 0, b_odd = 0;

        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            if (b % 2 == 0) {
                a_even++;
            } else {
                a_odd++;
            }
        }

        int m;
        cin >> m;

        for (int i = 0; i < m; i++) {
            int b;
            cin >> b;
            if (b % 2 == 0) {
                b_even++;
            } else {
                b_odd++;
            }
        }

        cout << a_even * 1LL * b_even + a_odd * 1LL * b_odd << "\n";
    }

    return 0;
}
