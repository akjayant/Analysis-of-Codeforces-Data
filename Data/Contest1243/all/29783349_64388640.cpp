#include <iostream>
#include <cmath>
using namespace std;
typedef long long int ll;

bool isprime(ll);

bool primes[1000009];

int main()
{
    long long int n;

    cin >> n;

    if (isprime(n))
    {
        cout << n << endl;
        return 0;
    }

    int B = (int)sqrt(n)+10;

    for (int i = 1; i <= 1000000; i++)
    {
        primes[i] = true;
    }

    for (int i = 2; i <= 1000000; i++)
    {
        for (int j = 2*i; j <= 1000000; j+=i)
        {
            primes[j] = false;
        }
    }

    int p = 2;

    while (n%p != 0)
    {
        p++;
    }

    while (n%p == 0)
    {
        n /= p;
    }

    if (n == 1)
    {
        cout << p << endl;
    }
    else
    {
        cout << 1 << endl;
    }
}

bool isprime(ll x)
{
    int B = (int)(sqrt(x))+10;

    for (int i = 2; i <= B && i < x; i++)
        if (x%i == 0)
            return false;

    return true;
}
