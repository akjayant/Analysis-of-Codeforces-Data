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

const int N = 1e6 + 5e5;
const int M = 1e6 + 5e5;
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

    int n, p, w, d;
    cin >> n >> p >> w >> d;
    for(int i = 0; i <= M; i++)
    {
        int x = i;
        int y = (p - x * w);
        if (y >= 0 && y % d == 0)
        {
            y /= d;
            int z = n - x - y;
            if (z >= 0)
            {
                cout << x << " " << y << " " << z;
                return 0;
            }
        }

        y = i;
        x = (p - y * d);
        if (x >=0 && x % w == 0)
        {
            x /= w;
            int z = n - x - y;
            if (z >= 0)
            {
                cout << x << " " << y << " " << z;
                return 0;
            }
        }
    }

    cout << -1;


}
