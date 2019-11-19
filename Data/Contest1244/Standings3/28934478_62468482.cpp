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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        string s;
        cin >> n >> s;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                mx = max(mx, n - i);
                mx = max(mx, i + 1);
            }
        }
        cout << max(n, 2 * mx) << '\n';
    }
}