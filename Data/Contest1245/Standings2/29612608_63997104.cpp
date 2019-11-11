#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int N = 1e2 + 10;
const int mod = 1e9 + 7;

#define int long long

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (__gcd(a, b) == 1)
        {
            cout << "Finite\n";
        } else
        {
            cout << "Infinite\n";
        }
    }

    return 0;
}
