#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <limits>
#include <unordered_set>
using namespace std;

using ll = long long;

ll MOD = 1073741824;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int ans = (a + c - 1) / c + (b + d - 1) / d;
        if (ans > k) {
            cout << -1 << endl;
        } else {
            cout <<  (a + c - 1) / c << " " <<  (b + d - 1) / d << endl;
        }
    }
}
