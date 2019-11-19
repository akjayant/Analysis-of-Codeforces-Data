#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <stack>
#include <fstream>
#include <random>
#include <fstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int ans = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans = max(ans, 2 * (i + 1));
                ans = max(ans, 2 * (n - i));
            }
        }
        cout << ans << endl;
    }

    return 0;
}