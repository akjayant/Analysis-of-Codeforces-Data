#include <bits/stdc++.h>
using namespace std;

long long factorize(long long n)
{
    long long res = -1;
    long long count = 0;

    // count the number of times 2 divides
    while (!(n % 2)) {
        n >>= 1; // equivalent to n=n/2;
        count++;
    }

    // if 2 divides it
    if (count){
        //cout << 2 << "  " << count << endl;
        res=2;
    }

    // check for all the possible numbers that can
    // divide it
    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count){
            //cout << i << "  " << count << endl;
            if (res > 0){
                return -1;
            }
            res = i;
        }
    }

    // if n at the end is a prime number.
    if (n > 2){
        //cout << n << "  " << 1 << endl;
        if (res > 0){
            return -1;
        }
        res = n;
    }
    return res;
}

int main() {
    long long n;
    cin>>n;
    long long res = factorize(n);
    if (res <0){
        cout<<1;
    } else {
        cout<<res;
    }
    return 0;
}
