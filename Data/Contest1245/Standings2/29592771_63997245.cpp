#include <bits/stdc++.h>

using namespace std;

long long t, a, b;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(__gcd(a, b) != 1)
            cout << "Infinite\n";
        else cout << "Finite\n";
    }
    return 0;
}
