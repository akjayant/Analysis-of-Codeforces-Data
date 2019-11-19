#include <bits/stdc++.h>

using namespace std;

int t, a, b, k, c, d;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> d >> k;
        bool gasit = false;
        int x, y;
        for (int i = 0; i <= 100 && !gasit; ++i)
        {
            for (int j = 0; j <= 100 && !gasit; ++j)
            {
                if (i + j <= k && i * c >= a && j * d >= b)
                {
                    gasit = true;
                    x = i;
                    y = j;
                }
            }
        }
        if (gasit == false)
            cout << -1 << "\n";
        else
            cout << x << " " << y << "\n";

    }
    return 0;
}
