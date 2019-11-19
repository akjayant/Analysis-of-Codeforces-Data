#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <ctime>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, k;
        cin >> a >> c >> b >> d >> k;
        int res = (a + b - 1) / b + (c + d - 1) / d;
        if (res <= k) {
            cout << (a + b - 1) / b << ' ' << (c + d - 1) / d;
        } else {
            cout << -1;
        }
        cout << '\n';
    }
}