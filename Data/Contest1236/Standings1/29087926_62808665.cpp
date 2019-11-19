#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <complex>
#include <bitset>

using namespace std;
using ll=long long int;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (auto &e: a) {
        cin >> e;
        --e;
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> u(n+m, 0), d(n+m, 0);
    fill(u.begin() + m, u.end(), 1);
    fill(d.begin(), d.begin() + n, 1);

    for (int i = 0; i < m; ++i) {
        int ub = m - i;
        int db = i;
        if (a[i] != 0) {
            u[ub + a[i] - 2] += u[ub + a[i] - 1];
            u[ub + a[i] - 1] = 0;
        }
        if (a[i] != n-1) {
            d[db + a[i] + 2] += d[db + a[i] + 1];
            d[db + a[i] + 1] = 0;
        }
    }

    ll ans = n * n;
    for (int i = 1; i <= n-1; ++i) {
        int b = -1;
        ans -= (n-i-1) * u[b+i];
    }
    for (int i = 0; i <= n-2; ++i) {
        int b = m+1;
        ans -= i * d[b+i];
    }

    cout << ans << endl;

    return 0;
}
