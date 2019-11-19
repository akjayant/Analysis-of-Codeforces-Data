#include <iostream>

using namespace std;

int main()
{
    int t; cin >> t;

    while(t--)
    {
        int n, m;
        int p1 = 0, i1 = 0, p2 = 0, i2 = 0;

        cin >> n;

        for(int i = 1; i <= n; i++)
        {
            int x; cin >> x;

            if(x % 2 == 0) p1++;
            else i1++;
        }

        cin >> m;

        for(int i = 1; i <= m; i++)
        {
            int x; cin >> x;

            if(x % 2 == 0) p2++;
            else i2++;
        }

        cout << 1LL * p1 * p2 + 1LL * i1 * i2 << '\n';
    }

    return 0;
}
