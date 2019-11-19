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

const int N = 1e5 + 100;
const int M = 1e6 + 5e5;
const ll mod = 1e9 + 7;
const ll MOD = 998244353;
const int P = 1336;
const ld eps = 0.000000001;
const int inf = 1e18 + 7;

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

vector <int> a;
vector <int> g[N];
int dp[N][3][3];
int c[N][3];
int ot[N];

void DFS(int v, int pr)
{
    a.pb(v);
    for(auto to: g[v])
    {
        if (to == pr) continue;
        DFS(to, v);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int z = 0; z < 3; z++)
            {
                dp[i][j][z] = inf;
            }
        }
    }

    int n;
    cin >> n;
    for(int j = 0; j < 3; j++)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    int root = -1;
    for(int i = 0; i < n; i++)
    {
        if (g[i].size() > 2)
        {
            cout << -1;
            return 0;
        }
        if (g[i].size() == 1) root = i;
    }

    DFS(root, root);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (i == j) continue;
            dp[1][i][j] = c[a[0]][i] + c[a[1]][j];
        }
    }

    for(int i = 2; i < n; i++)
    {
        for(int c1 = 0; c1 < 3; c1++)
        {
            for(int c2 = 0; c2 < 3; c2++)
            {
                for(int c3 = 0; c3 < 3; c3++)
                {
                    if ((c1 == c2) || (c1 == c3) || (c2 == c3)) continue;
                    dp[i][c2][c3] = min(dp[i][c2][c3], dp[i - 1][c1][c2] + c[a[i]][c3]);
                }
            }
        }
    }

    int ans = inf;
    int c2, c3;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
             if (ans > dp[n - 1][j][i])
             {
                 ans = dp[n - 1][j][i];
                 c2 = j; c3 = i;
             }
        }
    }


    ot[a[n - 1]] = c3;
    ot[a[n - 2]] = c2;

    for(int i = n - 3; i >= 0; i--)
    {
        int cc;
        for(int c1 = 0; c1 < 3; c1++)
        {
            if (c1 == c2 || c1 == c3) continue;
            if (dp[i + 1][c1][c2] + c[a[i + 2]][c3] == dp[i + 2][c2][c3])
            {
                ot[a[i]] = c1;
                c3 = c2;
                c2 = c1;
                break;
            }
        }
    }

    cout << ans << endl;
    for(int i = 0; i < n; i++)
    {
        cout << ot[i] + 1 << " ";
    }

}
