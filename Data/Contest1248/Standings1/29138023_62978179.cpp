#include <bits/stdc++.h>

#define int long long
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, x) for(int i = 0; i < x; i++)
#define rforn(i, x) for(int i = x - 1; i >= 0; i--)

using namespace std;

template<typename T> void print(T a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn (i, n)
        cin >> a[i];

    int m;
    cin >> m;
    vector<int> b(m);
    forn (i, m)
        cin >> b[i];

    int cnt1 = 0, cnt2 = 0;
    forn (i, n)
        if (a[i] % 2 == 0)
            cnt1++;
        else
            cnt2++;

    int cnt3 = 0, cnt4 = 0;
    forn (i, m)
        if (b[i] % 2 == 0)
            cnt3++;
        else
            cnt4++;

    cout << cnt1 * cnt3 + cnt2 * cnt4 << '\n';
}

signed main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    forn (i, q)
        solve();

    return 0;
}
