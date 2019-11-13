#pragma GCC optimize("-Ofast")

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define sqr(x) (x) * (x)

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    for(int ii = 0; ii < k; ++ii)
    {
        int n;
        cin >> n;
        vector <int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.rbegin(), a.rend());
        int mn = 1005;
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            mn = min(mn, a[i]);
            ans = max(ans, min(mn, i + 1));
        }
        cout << ans << '\n';
    }
    return 0;
}
