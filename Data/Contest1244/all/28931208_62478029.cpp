#include <iostream>
#include <vector>
#include <functional>
#include <set>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

void solve() {
    int n;
    int64_t k;
    cin >> n >> k;
    vector<pair<int, int>> a;
    {
        vector<int> b(n);
        for (auto& val : b)
            cin >> val;
        sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (j < n && b[i] == b[j])
                ++j;
            a.emplace_back(b[i], j - i);
            i = j - 1;
        }
    }
    n = (int)a.size();
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i].second > k && a[j].second > k)
            break;
        if (a[i].second < a[j].second) {
            int64_t t = a[i + 1].first - a[i].first;
            if (t * a[i].second <= k) {
                k -= t * a[i].second;
                a[i + 1].second += a[i].second;
                ++i;
            } else {
                int64_t w = k / a[i].second;
                k -= w * a[i].second;
                a[i].first += w;
            }
        } else {
            int64_t t = a[j].first - a[j - 1].first;
            if (t * a[j].second <= k) {
                k -= t * a[j].second;
                a[j - 1].second += a[j].second;
                --j;
            } else {
                int64_t w = k / a[j].second;
                k -= w * a[j].second;
                a[j].first -= w;
            }
        }
    }
    cout << a[j].first - a[i].first << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}