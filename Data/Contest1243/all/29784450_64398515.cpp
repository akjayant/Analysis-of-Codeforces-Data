#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int x = sqrt(n);
    long long int g = n;
    for (long long int i = 2; i <= x; i++)
    {
        if (n % i == 0)
        {
            g = __gcd(g, i);
            g = __gcd(g, n / i);
        }
    }
    cout << g << endl;
}