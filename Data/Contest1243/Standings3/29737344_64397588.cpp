#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool prime(ll x)
{
    for(ll i =2; i*i<=x; i++)
    {
        if (x%i==0) return false;
    }
    return true;
}

int main()
{
    ll n;
    cin>>n;
    if (prime(n) || (n == 1))
    {
        cout<<n;
        return 0;
    }

    vector <ll> p;
    ll w = sqrt(n);
    for(ll i = 2; i<=w+1; i++)
    {
        while (n%i==0)
        {
            p.push_back(i);
            n/=i;
        }
    }
    if (n > 1)
        p.push_back(n);

    if (p[0] == p[p.size()-1])
    {
        cout<<p[0];
    }
    else
        cout<<1;





    return 0;
}
