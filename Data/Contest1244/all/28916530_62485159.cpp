#include <bits/stdc++.h>
using namespace std;
#define pb  push_back
#define ll  long long
#define vi  vector<ll >
#define vvi vector<vi >
#define all(x) x.begin(), x.end()

ll n, k;
ll il, ir, nl, nr;
vi a;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));

    il = 0;
    ir = n - 1;
    nl = nr = 1;

    while (true) {
        if (il == ir) {
            cout << 0;
            return 0;
        }
        if (nl <= nr) {
            ll dist = a[il + 1] - a[il];
            if (nl * dist <= k) {
                k -= nl * dist;
                ++il; ++nl;
            }
            else {
                cout << a[ir] - a[il] - (k / nl);
                return 0;
            }
        }
        else {
            ll dist = a[ir] - a[ir - 1];
            if (nr * dist <= k) {
                k -= nr * dist;
                --ir; ++nr;
            }
            else {
                cout << a[ir] - a[il] - (k / nr);
                return 0;
            }
        }
    }

    return 0;
}
