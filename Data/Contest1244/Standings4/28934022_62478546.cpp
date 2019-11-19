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

    ll n, p, w, d, x, y, z;
    cin >> n >> p >> w >> d;
    for (x = p / w; x >= max(0ll, p / w - d - 1); --x) {
        if ((x * w) % d == (p % d)) {
            y = (p - x * w) / d;
            if (x + y <= n) {
                cout << x << ' ' << y << ' ' << n - x - y << '\n';
            } else {
                cout << -1 << '\n';
            }
            return 0;
        }
    }

    cout << -1;
    return 0;
}
