#include <bits/stdc++.h>
#define INF 1e18
#define M 1000000007
#define ll long long
using namespace std;

int seive[1000006];

bool is_prime(ll n)
{
    for(ll i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0; i <= 1000000; i++)
    {
        seive[i] = 1;
    }
    seive[0] = 0;
    seive[1] = 0;
    for(ll i = 2; i <= 1000000; i++)
    {
        if(seive[i])
        {
            for(ll j = i*i; j <= 1000000; j += i)
            {
                seive[j] = 0;
            }
        }
    }
    ll n;
    cin >> n;
    if(is_prime(n))
    {
        cout << n << endl;
    }
    else
    {
        ll p;
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(seive[i] == 1 && n % i == 0)
            {
                p = i;
                break;
            }
        }
        while(n % p == 0)
        {
            n /= p;
        }
        if(n == 1)
        {
            cout << p << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
}