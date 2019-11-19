#include <bits/stdc++.h>

using namespace std;

int t;
void read()
{
    cin >> t;
}

bool is[1024];
void solve()
{
    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        for (int i = 1; i <= n; i++)
        {
            if (s[i-1] == '1')
                is[i] = 1;

            else
                is[i] = 0;
        }

        int ans = n;
        for (int i = 1; i <= n; i++)
            if (is[i])
            ans++;

        for (int i = 1; i <= n; i++)
            if (is[i])
            ans = max(ans, 2 * max(i, n - i + 1));

        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    read();
    solve();
}
