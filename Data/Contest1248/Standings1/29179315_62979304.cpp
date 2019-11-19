#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iomanip>
#include <queue>

using namespace std;


const int inf = (int) 1e9;
const int max_n = 1e5;

#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()

int p[max_n], q[max_n];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            cin >> q[j];
        }
        ll cnt_p[2], cnt_q[2];
        fill(cnt_p, cnt_p + 2, 0);
        fill(cnt_q, cnt_q + 2, 0);
        for (int i = 0; i < n; ++i) {
            cnt_p[p[i] % 2]++;
        }
        for (int i = 0; i < m; ++i) {
            cnt_q[q[i] % 2]++;
        }
        cout << cnt_p[0] * cnt_q[0] + cnt_p[1] * cnt_q[1] << "\n";
    }
    return 0;
}