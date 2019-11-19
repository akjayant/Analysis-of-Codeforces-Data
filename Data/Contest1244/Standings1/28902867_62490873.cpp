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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    vector <ll> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0;
    ll k1 = 1;
    int j = n - 1;
    ll k2 = 1;
    while(i < j)
    {
        while(i + 1 < n && a[i] == a[i + 1])
        {
            ++i;
            ++k1;
        }
        while(j - 1 >= 0 && a[j] == a[j - 1])
        {
            --j;
            ++k2;
        }
        if (i >= j) break;
        if (k1 < k2)
        {
            ll z = min(k / k1, a[i + 1] - a[i]);
            if (z == 0) break;
            k -= z * k1;
            a[i] += z;
        }
        else
        {
            ll z = min(k / k2, a[j] - a[j - 1]);
            if (z == 0) break;
            k -= z * k2;
            a[j] -= z;
        }
    }
//    cerr << i << ' ' << j << endl;
    if (i >= j) cout << 0;
        else cout << a[j] - a[i];
    return 0;
}
