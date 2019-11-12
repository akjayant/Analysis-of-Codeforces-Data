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
#define show(x) cout << "[debug " << __LINE__ << "] " << #x << " = " << x << endl
#define shows() cout << "=========================" << endl
#define debug cout << "[debug_scope " << __LINE__ << "]" << endl;
#else
#define show(x) ((void)0)
#define shows() ((void)0)
#define debug if (false)
#endif

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(all(v));
        reverse(all(v));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, min(i+1, v[i]));
        }

        cout << ans << "\n";
    }

    return 0;
}
