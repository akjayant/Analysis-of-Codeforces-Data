#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define pdd pair<double, double>
#define pii pair<int, int>
#define gcd __gcd

#ifdef LOCAL
#define DEBUG 1
#else
#define DEBUG 0
#endif
#define fast if (!DEBUG) {cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);}
#define debug if (DEBUG) cout
#define endl '\n'

typedef long long ll;
using namespace std;

const int N = 200001;
const ll M = 1000000007;

int t, n;
string s;

main() { fast;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int l = 100000, r = -1, c = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                c++;
                l = min(l, i);
                r = max(r, i);
            }
        }

        int ans = n + c;
        if (c != 0) {
            ans = max({ans, (n - l) * 2, (r + 1) * 2});
        }

        cout << ans << endl;
    }
}
