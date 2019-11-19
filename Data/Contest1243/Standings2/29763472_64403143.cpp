#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> p;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cout.tie(0);
    cout.sync_with_stdio(false);
    
    
    ll n;
    cin >> n;

    for(ll i=2;i*i<=n;i++)
    {
        ll g =0;
        while(n%i == 0)
        {
            n/=i;
            g++;
        }
        if(g)
        {
            if(n!=1)
            {
                cout << 1;
                return 0;
            }
            else
            {
                cout << i;
                return 0;
            }
        }

    }
    cout << n;
    return 0;
}
