#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int n, m, t;

void solve() {
    long long odd1 = 0, even1 = 0, odd2 = 0, even2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 0) {
            even1++;
        } else {
            odd1++;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 0) {
            even2++;
        } else {
            odd2++;
        }
    }
    long long ans = odd1*odd2 + even1 * even2;
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}