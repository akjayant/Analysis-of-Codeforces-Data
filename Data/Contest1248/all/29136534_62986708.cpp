#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        ll e=0, o=0, a=0, b=0;
        for (ll i=0, x ; i<n ; i++)
        {
            cin >> x;
            if (x%2)
                o++;
            else
                e++;
        }
        ll m; cin >> m;
        for (ll i=0, x ; i<m ; i++)
        {
            cin >> x;
            if (x%2)
                b++;
            else
                a++;
        }
        cout << (e*a)+(o*b) << endl;
    }
    return 0;
}
