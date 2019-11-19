#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double
#define sqr(x) (x) * (x)
//#define all(a) a.begin(), a.end()

using namespace std;
using namespace __gnu_pbds;

typedef tree<
pair <int, int>,
null_type,
greater<pair <int, int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int maxn = 1003;
bool kek[maxn];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int ii = 0; ii < t; ++ii)
    {
        int n;
        cin >> n;
        vector <int> p;
        for(int i = 1; i <= n; ++i)
        {
            char c;
            cin >> c;
            if (c == '0') kek[i] = false;
                else
                {
                    kek[i] = true;
                    p.pb(i);
                }

        }
        if (int(p.size()) == 0)
        {
            cout << n << '\n';
            continue;
        }
        int ans = n;
        int f = p.front();
        int s = p.back();
        ans = max(ans, (n - f + 1) * 2);
        ans = max(ans, s * 2);
        cout << ans << '\n';
    }

    return 0;
}
