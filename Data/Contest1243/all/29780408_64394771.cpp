#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool is_prime(ll n)
{

        return 1;
    return 0;
}

int main()
{
    ll n;
    cin >> n;
    ll sq = sqrt(n);
    for (ll i=2; i<=sq; ++i)
    {
        if (n%i==0)
        {
            while (n%i == 0)
                n/=i;
            if (n != 1)
                cout << 1;
            else
                cout << i;
            return 0;
        }

    }
    cout << n;

    return 0;
}









