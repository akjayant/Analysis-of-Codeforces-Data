#include <bits/stdc++.h>

using namespace std;

const int N = 2e5, INF = 1e9;
long long t, n, a[N];
set<long long> d;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    if (n == 1)
    {
        cout << "1\n";
        return 0;
    }

    for (long long i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            d.insert(i);
            n /= i;
        }
    }

    if (n > 1)
    {
        d.insert(n);
    }

    if (d.size() == 1)
    {
        cout << (*d.begin()) << "\n";
    }
    else
    {
        cout << 1 << "\n";
    }
    
}