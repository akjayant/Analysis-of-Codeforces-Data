#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <ctime>
#include <string>
 
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, p, w, d;
    cin >> n >> p >> w >> d;
    int k = p / w;
    int i = 0;
    while (i <= d && k >= 0) {
        if ((p - k * w) % d == 0) {
            if (k + (p - k * w) / d <= n) {
                cout << k << ' ' << (p - k * w) / d << ' ' << n - (k + (p - k * w) / d) << '\n';
            } else {
                cout << "-1\n";
            }
            return 0;
        }
        i++;
        k--;
    }
    cout << "-1\n";
}