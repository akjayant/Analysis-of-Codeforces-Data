#pragma GCC optimize("-Ofast")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define sqr(x) (x) * (x)

using namespace std;
using namespace __gnu_pbds;

const ll bb = 100000;

unordered_set <ll> st;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        if (y > x) swap(x, y);
        st.insert(1ll * x * bb + y);
    }
    unordered_set <int> unused;
    for(int i = 1; i < n; ++i)
        unused.insert(i);
    queue <int> q;
    q.push(0);
    int ans = 0;
    int tt = 3;
    while(!unused.empty())
    {
        int v = q.front();
        q.pop();
        vector <int> ud;
        for(int u : unused)
        {
            int x = v;
            int y = u;
            if (y > x) swap(x, y);
            ll tet = 1ll * x * bb + y;
            if (st.count(tet) == 0)
            {
                q.push(u);
                ud.pb(u);
            }
        }
        for(int i : ud)
            unused.erase(i);
        if (q.empty() && !unused.empty())
        {
            ++ans;
            int kek;
            for(int u : unused)
            {
                kek = u;
                break;
            }
            q.push(kek);
            unused.erase(kek);
        }
    }
    cout << ans;
    return 0;
}
