#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
ll prime = 1000000007;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t, a, b, c, d, v;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> a >> b >> c >> d >> v;
        ll m = (c + a - 1) / c + (d + b - 1) / d;
        if (m <= v) {
            cout << (c + a - 1) / c << ' ' << v - (c + a - 1) / c << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
