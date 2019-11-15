#include<bits/stdc++.h>
using namespace std;
long test;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> test;
    while (test--)
    {
        long a, b, d = 0;
        cin >> a >> b;
        for (long i = 1; i <= 1e4; i++)
        {
            if ((a * i - 1) % b == 0)
            {
                cout << "Finite" << '\n';
                d = 5;
                break;
            }
            if ((a * i + 1) % b == 0)
            {
                cout << "Finite" << '\n';
                d = 5;
                break;
            }

        }
        if (d > 0) continue;
        cout << "Infinite" << '\n';

    }
}
