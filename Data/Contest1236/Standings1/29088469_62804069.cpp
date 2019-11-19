#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <deque>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cassert>
#include <cstring>
#include <queue>
#include <random>

#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define mp(x, y) make_pair((x), (y))

using namespace std;

ll n, m;
ll f(vector<ll> v) {
    map<ll, ll> kek;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        kek[i] = 1;
        ans -= i;
    }

    for (int i = 0; i < m; ++i) {
        ll ind = v[i] - i - 1;
        kek[ind - 1] += kek[ind];
        kek[ind] = 0;
    }
    for (auto e : kek) {
        ans += min(n - 1, e.fi + m + 1) * e.se;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    cin >> n >> m;
    vector<ll> vec(m);
    for (int i = 0; i < m; ++i) {
        cin >> vec[i];
        vec[i]--;
    }
    if (n == 1) {
        if (m >= 1) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
        return 0;
    }

    ll ans = f(vec);
    for (int i = 0; i < m; ++i) {
        vec[i] = n - vec[i] - 1;
    }
    ans += f(vec);
    cout << (ans + n) << endl;
    
    return 0;
}