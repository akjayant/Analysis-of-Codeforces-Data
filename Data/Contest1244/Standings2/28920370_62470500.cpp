#include <bits/stdc++.h>

//#include <ext/pb_ds/detail/standard_policies.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define int long long

using namespace std;

//using namespace __gnu_pbds;
//template <typename T> using ordered_set = tree <T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e6 + 100;
const int M = 200;
const ll mod = 1e9 + 7;
const ll MOD = 998244353;
const int P = 1336;
const ld eps = 0.000000001;
const int inf = 1e9 + 7;

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int fi = -1, ls;
        for(int i = 0; i < n; i++)
        {
            char a;
            cin >> a;
            if (a == '1')
            {
                if (fi == -1) fi = i;
                ls = i;
            }
        }
        if (fi == -1)
        {
            cout << n << endl;
            continue;
        }
        fi++; ls++;

        int ans = n + 1;
        ans = max(ans, 2 * fi);
        ans = max(ans, 2 * ls);
        ans = max(ans, (n - fi + 1) * 2);
        ans = max(ans, (n - ls + 1) * 2);

        cout << ans << endl;

    }

}
