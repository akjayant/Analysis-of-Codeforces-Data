#include <bits/stdc++.h>

using namespace std;

#define ll long long

int gcd(int a, int b)
{
    while (b)
    {
        a%=b;
        swap(a, b);
    }
    return a;
}

int main()
{
    int q;
    cin >> q;
    for (int _i = 0; _i < q; ++_i)
    {
        int a, b;
        cin >> a >> b;
        if (gcd(a, b) == 1)
            cout << "Finite";
        else
            cout << "Infinite";
        cout << "\n";
    }

    return 0;
}









