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

int t, a, b, c, d, k;

main() { fast;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d >> k;

        if (ceil(1.0 * a / c) + ceil(1.0 * b / d) > k) cout << -1;
        else cout << (int)ceil(1.0 * a / c) << " " << (int)ceil(1.0 * b / d);
        cout << endl;
    }
}
