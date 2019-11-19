#include <bits/stdc++.h>

using namespace std;

int t;
void read()
{
    cin >> t;
}

void solve()
{
    while (t--)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        bool can = false;

        for (int i = 0; i <= k; i++)
            if (c * i >= a && (k - i) * d >= b)
            {
                can = true;
                cout << i << " " << k - i << endl;
                break;
            }


        if (!can)
            cout << -1 << endl;
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
