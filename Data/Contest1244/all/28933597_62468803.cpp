#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cassert>
#include <unordered_map>

#define ll long long

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = n;
        int min_ = -1;
        int max_ = -1;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (min_ == -1) {
                    min_ = i;
                }
                max_ = i;
            }
        }
        if (min_ != -1) {
            int aa = max(2 * (min_ + 1), 2 * (n - min_));
            int bb = max(2 * (max_ + 1), 2 * (n - max_));
            ans = max(aa, bb);
        }
        cout << ans << "\n";
    }
}
