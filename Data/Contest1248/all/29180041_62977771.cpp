#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int o = 0; o < t; ++o)
    {
        int n, m;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i], a[i] %= 2;
        cin >> m;
        int b[m];
        for (int i = 0; i < m; ++i)
            cin >> b[i], b[i] %= 2;
        ll c = count(a, a + n, 0) * (ll)count(b, b + m, 0) + count(a, a + n, 1) * (ll)count(b, b + m, 1);
        cout << c << '\n';
    }
    return 0;
}
