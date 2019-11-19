#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int x;
    cin >> x;
    long long int k = x;
    if(x == 1)
    {
        cout << 1;
        return 0;
    }

    set<long long int> factors;

    for (long long int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            factors.insert(i);
            x /= i;
        }
    }

    if (x != 1) {
        factors.insert(x);
    }
    if(factors.size() == 1)
        cout << *factors.begin();
    else cout << 1;
}
