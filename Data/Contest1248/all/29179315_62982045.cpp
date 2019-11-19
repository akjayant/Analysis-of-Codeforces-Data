#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iomanip>
#include <queue>

using namespace std;


const int inf = (int) 1e9;
const int max_n = 1e5;

#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()

ll a[max_n];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    ll h = 0, w = 0;
    for (int i = 0; i < n / 2 + n % 2; ++i) {
        h += a[i];
    }
    for (int i = n/ 2 + n % 2; i < n; ++i) {
        w += a[i];
    }
    cout << h * h + w * w;
    return 0;
}