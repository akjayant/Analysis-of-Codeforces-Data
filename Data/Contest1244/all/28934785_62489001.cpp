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

long long n, k, a, l = 1, r = 1, ans = 0;
vector<int> values;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        values.push_back(a);
    }
    sort(values.begin(), values.end());
    if (values[0] == values[n -1]) {
        cout << 0 << endl;
        return 0;
    }
    ans = values[n-1] - values[0];
    int from = 0;
    int to = n - 1;
    while (values[from] == values[from + 1]) {
        from++;
        l++;
    }
    while (values[to] == values[to - 1]) {
        to--;
        r++;
    }

    while (true) {
        if (l < r) {
            int delta = values[from + 1] - values[from];
            if (l * delta <= k) {
                k -= l * delta;
                from++;
                l++;
                while (from + 1 < n && values[from] == values[from + 1]) {
                    from++;
                    l++;
                }
            } else {
                values[from] += k / (l);
                cout << values[to] - values[from] << endl;
                return 0;
            }
        } else {
            int delta = values[to] - values[to - 1];
            if (r * delta <= k) {
                k -= r * delta;
                to--;
                r++;
                while (to - 1 >= 0 && values[to] == values[to - 1]) {
                    to--;
                    r++;
                }
            } else {
                values[to] -= k / (r);
                cout << values[to] - values[from] << endl;
                return 0;
            }
        }
        if (from >= to) {
            cout << 0 << endl;
            return 0;
        }
    }
}