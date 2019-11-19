#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int cnt1 = (a + c - 1) / c;
        int cnt2 = (b + d - 1) / d;
        if(cnt1 + cnt2 <= k)
            cout << cnt1 << ' ' << cnt2 << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}
