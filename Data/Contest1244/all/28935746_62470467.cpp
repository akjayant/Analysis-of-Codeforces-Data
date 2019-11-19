#include <bits/stdc++.h>

#define llong long long

using namespace std;

int  main(void)
{
    llong t = 0, n = 0, ans = 0, x = 0, y = 0;
    string s;
    cin >> t;
    for (llong r = 0; r < t; r++)
    {
        cin >> n;
        cin >> s;
        ans = n;
        x = -1;
        y = -1;
        for (llong i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                x = i;
                break;
            }
        }
        for (llong i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                y = i;
                break;
            }
        }
        if (x != -1 && y != -1)
        {
            ans = max(ans, (y - x) * 2 + max(n - y, x + 1) * 2);
        }
        cout << ans << '\n';
    }
    return 0;
}

