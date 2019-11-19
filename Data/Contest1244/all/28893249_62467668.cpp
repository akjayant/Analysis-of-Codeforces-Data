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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = -1, r = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                r = i;
                if (l < 0) {
                    l = i;
                }
            }
        }
        if (r < 0) {
            cout << n << endl;
        } else {
            int x = -1;
            l++; r++;
            x = max(l, n - r + 1);
            x = max(x, n - l + 1);
            x = max(x, r);
            cout << max(n, 2 * x) << endl;
        }
    }
}
