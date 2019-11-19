#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdio>

#define fastIO do { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); } while (false);

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int solve() {
    int n;
    cin >> n;

    vector<bool> v(n);
    for (int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;

        v[i] = (tmp == '1');
    }

    int cnt = count(v.begin(), v.end(), true);
    if (cnt == 0) {
        return n;
    }

    int first = 0, last = 0;
    for (int i = 0; i < n; i++) {
        if (v[i]) {
            first = i;
            break;
        }
    }
    for (int i = n - 1; 0 <= i; i--) {
        if (v[i]) {
            last = i;
            break;
        }
    }

    int mb1 = (last + 1) * 2;
    int mb2 = (n - first) * 2;

    return max(mb1, mb2);
}

int main() {
    fastIO;

    int t;
    cin >> t;

    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}