#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

#define ff first
#define ss second

const double eps = 1e-6;
const int mod = 45;
const int maxn = 1e5 + 7;

int main() {
#ifdef JOPA
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        ll one = 0, zero = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2) {
                one++;
            } else {
                zero++;
            }
        }
        cin >> m;
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            if (x % 2) {
                ans += one;
            } else {
                ans += zero;
            }
        }
        cout << ans << "\n";
    }


    return 0;
}
