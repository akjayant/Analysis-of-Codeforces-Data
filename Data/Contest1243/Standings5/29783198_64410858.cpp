#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool is_prime(long long x){
    if(x == 2 || x == 3 || x == 5)
        return true;

    for(long long a = 2; a <= sqrtl(x)+1; a++)
        if(x % a == 0)
            return false;
    return true;
}

vector<long long> primes;

void generate_primes(){
    for(long long x = 2; x <= 1000000; x++)
        if(is_prime(x))
            primes.push_back(x);
}

int main()
{
    generate_primes();

    long long x;
    cin >> x;

    if(is_prime(x)){
        cout << x << endl;
        return 0;
    }

    for(long long d : primes){
        long long cp = x;
        while(cp > 1 && (cp % d == 0))
            cp /= d;

        if(cp == 1){
            cout << d << endl;
            return 0;
        }
    }

    cout << 1 << endl;
    return 0;
}
