#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <limits>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#define int long long
using namespace std;

using ll = long long;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto& x: v) {
        cin >> x;
    }
    sort(rbegin(v), rend(v));
    long long a = 0, b = 0;
    for (int i =0 ;i < n; i++) {
        if (i <= (n-1) / 2) {
            a += v[i];
        } else {
            b += v[i];
        }
    }
    cout << a * a + b * b << endl;
}
