#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iterator>

#define mod 1000000007

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    long long min_prime = 1;
    if (n%2 == 0) {
        min_prime = 2;
    }
    else {
        for (long long p = 3; p*p<=n; p+=2) {
            if (n%p == 0) {
                min_prime = p;
                break;
            }
        }
    }
    if (min_prime == 1) {
        cout << n;
        return 0;
    }
    while (n%min_prime == 0) {
        n /= min_prime;
    }
    if (n == 1) {
        cout << min_prime;
    }
    else {
        cout << 1;
    }
    return 0;
}