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

    int t, n;
    string str;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> str;

        if (count(str.begin(), str.end(), '1') == 0) cout << n << endl;
        else {
            int res = 0;
            for (int i = 0; i < n; i++)
                if (str[i] == '1') res = max(res, i+1);
            for (int i = 1; i <= n; i++)
                if (str[n-i] == '1') res = max(res, i);

            cout << 2*res << endl;
        }
    }

    return 0;
}
