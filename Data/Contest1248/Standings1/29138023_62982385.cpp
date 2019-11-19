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

signed main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    forn (i, n)
        cin >> a[i];

    sort(all(a));

    int sum1 = 0, sum2 = 0;
    forn (i, n / 2)
        sum1 += a[i];
    for (int i = n / 2; i < n; i++)
        sum2 += a[i];

    cout << sum1 * sum1 + sum2 * sum2;
    return 0;
}
