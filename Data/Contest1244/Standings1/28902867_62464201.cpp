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

//const int maxn = 100003;

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
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int kek1 = a / c;
        int kek2 = b / d;
        if (a % c > 0) ++kek1;
        if (b % d > 0) ++kek2;
        if (kek1 + kek2 > k) cout << "-1\n";
            else cout << kek1 << ' ' << kek2 << '\n';
    }

    return 0;
}
