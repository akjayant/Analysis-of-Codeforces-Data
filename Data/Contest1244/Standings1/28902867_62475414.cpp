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
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    set <int> st;
    ll k = 0;
    while(p >= 0)
    {
        if (st.find(p % w) != st.end())
        {
            break;
        }
        if (p % w == 0)
        {
            ll c = p / w;
            if (n >= c + k)
            {
                cout << c << ' ' << k << ' ' << n - k - c;
                return 0;
            }
        }
        st.insert(p % w);
        p -= d;
        ++k;
    }
    cout << -1;
    return 0;
}
