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

const int maxn = 100030;
int c[maxn][3];
vector <int> g[maxn];

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
    cin >> n;
    for(int cl = 0; cl < 3; ++cl)
    {
        for(int i = 0; i < n; ++i)
            cin >> c[i][cl];
    }
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[v].pb(u);
        g[u].pb(v);
    }
    for(int i = 0; i < n; ++i)
        if (int(g[i].size()) > 2)
    {
        cout << -1;
        return 0;
    }
    int kek = 0;
    for(int i = 0; i < n; ++i)
        if (int(g[i].size()) == 1)
        {
            kek = i;
        }
    vector <int> vc;
    vc.pb(kek);
    int pr = -1;
    while(true)
    {
        bool f = true;
        for(auto to : g[kek])
        {
            if (to != pr)
            {
                f = false;
                pr = kek;
                kek = to;
                break;
            }
        }
        if (f) break;
        vc.pb(kek);
    }
    ll ans = 1e18;
    vector <int> lol(n);
    ll ot = 0;
    vector <int> geg(n);
    for(int i = 0; i < n; ++i)
    {
        ot += c[vc[i]][i % 3];
        geg[vc[i]] = i % 3;
    }
    ans = ot;
    lol = geg;

    ot = 0;
    for(int i = 0; i < n; ++i)
    {
        ot += c[vc[i]][(i + 1) % 3];
        geg[vc[i]] = (i + 1) % 3;
    }
    if (ot < ans)
    {
        ans = ot;
        lol = geg;
    }

    ot = 0;
    for(int i = 0; i < n; ++i)
    {
        ot += c[vc[i]][(i + 2) % 3];
        geg[vc[i]] = (i + 2) % 3;
    }
    if (ot < ans)
    {
        ans = ot;
        lol = geg;
    }


    reverse(vc.begin(), vc.end());

    ot = 0;
    for(int i = 0; i < n; ++i)
    {
        ot += c[vc[i]][i % 3];
        geg[vc[i]] = i % 3;
    }
    if (ot < ans)
    {
        ans = ot;
        lol = geg;
    }

    ot = 0;
    for(int i = 0; i < n; ++i)
    {
        ot += c[vc[i]][(i + 1) % 3];
        geg[vc[i]] = (i + 1) % 3;
    }
    if (ot < ans)
    {
        ans = ot;
        lol = geg;
    }

    ot = 0;
    for(int i = 0; i < n; ++i)
    {
        ot += c[vc[i]][(i + 2) % 3];
        geg[vc[i]] = (i + 2) % 3;
    }
    if (ot < ans)
    {
        ans = ot;
        lol = geg;
    }
    cout << ans << '\n';
    for(int i = 0; i < n; ++i)
        cout << lol[i] + 1 << ' ';
    return 0;
}
