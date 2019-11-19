#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    long long n, gc = 0;

    cin >> n;

    for (int i = 2; i <= (long long)sqrt(n); i++)
    {
        if (n % i == 0)
        {
            gc = gcd(gc, i);
            gc = gcd(gc, n / i);
        }
    }

    gc = gcd(gc, n);

    if (gc == 0LL)
    {
        cout << n;
        return 0;
    }

    cout << gc;
    return 0;
}
