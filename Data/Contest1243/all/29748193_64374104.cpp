#include <bits/stdc++.h>

using namespace std;

const int N = 2e5, INF = 1e9;
long long t, n, a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        int ans = 0;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);

        for (int i = 0; i < n; i++)
        {
            int x = min(a[i], n - i);
            ans = max(ans, x);
        }

        cout << ans << "\n";
    }
}