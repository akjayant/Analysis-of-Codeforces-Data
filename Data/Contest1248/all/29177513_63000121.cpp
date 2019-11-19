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

int b[N][2][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    if (n == 1 && m == 1)
    {
        cout << 2;
        return 0;
    }

    for(int f = 0; f < 2; f++)
    {
        for(int f1 = 0; f1 < 2; f1++)
        {
            b[1][f][f1] = 1;
        }
    }

    for(int i = 2; i < max(n, m); i++)
    {
        for(int f = 0; f < 2; f++)
        {
            for(int f1 = 0; f1 < 2; f1++)
            {
                for(int f2 = 0; f2 < 2; f2++)

                {
                    if (f == f1 && f2 == f1) continue;
                    b[i][f1][f] += b[i - 1][f2][f];
                    b[i][f1][f] %= mod;
                }
            }
        }
    }

    if (n == 1)
    {
        int ans = (b[m - 1][0][0] + b[m - 1][1][1] + b[m - 1][0][1] + b[m - 1][1][0]) % mod;
        cout << ans;
        return 0;
    }
    if (m == 1)
    {
        int ans = (b[n - 1][0][0] + b[n - 1][1][1] + b[n - 1][0][1] + b[n - 1][1][0]) % mod;
        cout << ans;
        return 0;
    }

    int ans = (b[m - 1][0][0] + b[m - 1][1][1] + b[m - 1][0][1] + b[m - 1][1][0]) % mod;
    ans -= 2;
    ans += mod;
    ans %= mod;
    ans += (b[n - 1][0][0] + b[n - 1][1][1] + b[n - 1][0][1] + b[n - 1][1][0]) % mod;
    ans %= mod;

    cout << ans;




}
