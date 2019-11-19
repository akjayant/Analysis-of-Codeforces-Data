// ContestCoding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using ll = long long;

std::set<long long> prime(long long n)
{
    std::set<long long> primes;
    while (n % 2 == 0)
    {
        primes.insert(2);
        n = n / 2;
    }

    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (long long i = 3U; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            primes.insert(i);
            n = n / i;
        }
    }

    if (n > 1)
        primes.insert(n);

    return primes;
}

using namespace std;

int main()
{
    long long n;
    cin >> n;

    auto primes = prime(n);

    if (primes.size() > 1)
        cout << "1";
    else if (primes.size() == 1)
    {
        auto a = *primes.begin();
        cout << a;
    }
    else
        cout << "1";
}
