#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define x first
#define y second
#define debug(x) cerr << #x << ": " << x << endl;
#define all(x) x.begin(), x.end()

typedef long long LL;
typedef pair <LL, LL> PLL;

const LL maxn = 100010;
const LL mod = 1000000007;
const LL inf = 2000000000;
const LL inf64 = inf*inf;


main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, a, b, c, d, k;
    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c >> d >> k;

        int res = -1;
        for (int i = 0; i <= k; i++)
            if (i*c >= a and d*(k-i) >= b)
                res = i;

        if (res == -1) cout << res << endl;
        else cout << res << " " << k-res << endl;
    }

    return 0;
}
