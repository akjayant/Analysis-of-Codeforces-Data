#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (ll)1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll maxi = -1;
        for (ll i = 0; i <= 100; i++)
        {
            for (ll j = 0; j <= 100; j++)
            {
                if (i <= a && 2 * i + j <= b && 2 * j <= c)
                {
                    maxi = max(maxi, 3 * (i + j));
                }
            }
        }
        cout << maxi << endl;
    }
}