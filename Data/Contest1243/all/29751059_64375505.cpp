#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        int n;
        cin >> n;

        vector<int> a(n + 1, 0);
        for (int i = 0, u; i < n; i++)
            cin >> u, ++a[u];
        for (int i = n - 1; ~i; i--)
            a[i] += a[i + 1];

        int ans;
        for (int i = 0; i <= n; i++)
            if (a[i] >= i)
                ans = i;
        cout << ans << '\n';
    }

    return 0;
}