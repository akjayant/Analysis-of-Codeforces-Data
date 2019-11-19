#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        int x = a / c + (a % c != 0);
        int y = b / d + (b % d != 0);

        if (x + y > k)
            cout << -1 << "\n";
        else 
            cout << x << " " << y << "\n";
    }


    return 0;
}