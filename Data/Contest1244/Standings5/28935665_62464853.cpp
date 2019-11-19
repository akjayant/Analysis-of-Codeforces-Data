#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    for(int qq = 0; qq < t; qq++)
    {
        int a, b, c, d, k, x, y;
        cin >> a >> b >> c >> d >> k;
        x = ((double)a / (double)c) + 0.999;
        y = ((double)b / (double)d) + 0.999;
        if(x + y <= k)
            cout << x << ' ' << y << '\n';
        else
            cout << "-1\n";
    }
    return 0;
}
