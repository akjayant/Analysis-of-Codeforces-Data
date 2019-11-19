#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    ll n;
    
    cin >> n;
    
    ll num_of_primes = 0;
    ll first_prime = -1;
    
    if (n % 2 == 0)
    {
        first_prime = 2;
        ++num_of_primes;
        
        while (n % 2 == 0)
        {
            n = n/2;
        }
    }
    
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            first_prime = i;
            ++num_of_primes;
            
            while (n % i == 0)
            {
                n = n/i;
            }
        }
    }
    
    if (n > 2)
    {
        first_prime = n;
        ++num_of_primes;
    }
    
    if (num_of_primes == 1)
    {
        cout << first_prime << endl;
    }
    else
    {
        cout << 1 << endl;
    }
}
