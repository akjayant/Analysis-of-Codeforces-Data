#include <bits/stdc++.h>

using namespace std;

int t, n, a[100010], res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        res = 0;
        for (int i = 1; i <= n; i++)
            res = max(res, min(a[i], n - i + 1));
        cout << res <<"\n";
    }
    return 0;
}
