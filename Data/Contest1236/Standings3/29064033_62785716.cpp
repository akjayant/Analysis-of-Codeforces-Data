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

    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c, res = 0;
        cin >> a >> b >> c;

        res += min(c/2*2, b*2) + min(c/2*2, b*2)/2;
        b -= min(c/2*2, b*2)/2;
        res += min(b/2*2, a*2) + min(b/2*2, a*2)/2;

        cout << res << endl;
    }

    return 0;
}
