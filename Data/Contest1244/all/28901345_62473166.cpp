#include <bits/stdc++.h>

using namespace std;

int t, n;
string x;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        int first1 = -1, last1 = -1;
        int maxim = 0;
        for (int i = 0; i < n; ++i)
        {
            if (x[i] == '1')
            {
                if (first1 == -1)
                    first1 = i + 1;
                last1 = i + 1;
            }
        }
        if (last1 == -1)
        {
            cout << n << "\n";
            continue;
        }
        maxim = n;
        maxim = max(maxim, last1 + max(last1, n - last1 + 1));
        maxim = max(maxim, n - first1 + 1 + max(first1, n - first1 + 1));
        cout << maxim << "\n";
    }
    return 0;
}
