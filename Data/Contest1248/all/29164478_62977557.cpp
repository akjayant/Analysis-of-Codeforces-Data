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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long a0 = 0, a1 = 0, b0 = 0, b1 = 0;
        for (int i = 0; i < n ; i++) {
            long long x;
            cin >> x;
            if (x % 2) {
                a1++;
            } else {
                a0++;
            }
        }
        int m;
        cin >> m;
        for (int i = 0; i < m ; i++) {
            long long x;
            cin >> x;
            if (x % 2) {
                b1++;
            } else {
                b0++;
            }
        }
        cout << a0 * b0 + a1 * b1 << endl;
    }
}
