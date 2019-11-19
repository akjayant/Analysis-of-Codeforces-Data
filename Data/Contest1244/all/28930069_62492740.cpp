#include <bits/stdc++.h>
//haha

using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define fileio freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);


signed main() {
    fastio
// fileio
    int n, k;
    cin >> n >> k;
    vector<int> a (n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<pair<int, int>> bb;
    int counter = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            bb.push_back({a[i - 1], counter});
            counter = 1;
        } else {
            ++counter;
        }
    }
    bb.push_back({a[n - 1], counter});
    int l = 0;
    int r = bb.size() - 1;
    while (l < r && k > 0) {
        if (bb[l].second < bb[r].second) {
            if (k >= (bb[l + 1].first - bb[l].first) * bb[l].second) {
                k -= (bb[l + 1].first - bb[l].first) * bb[l].second;
                bb[l + 1].second += bb[l].second;
                ++l;
            } else {
                bb[l].first += (k / bb[l].second);
                k = 0;
            }
        } else if (bb[l].second > bb[r].second) {
            if (k >= (bb[r].first - bb[r - 1].first) * bb[r].second) {
                k -= (bb[r].first - bb[r - 1].first) * bb[r].second;
                bb[r - 1].second += bb[r].second;
                --r;
            } else {
                bb[r].first -= (k / bb[r].second);
                k = 0;
            }
        } else {
            if ((bb[l + 1].first - bb[l].first) < (bb[r].first - bb[r - 1].first)) {
                if (k >= (bb[l + 1].first - bb[l].first) * bb[l].second) {
                    k -= (bb[l + 1].first - bb[l].first) * bb[l].second;
                    bb[l + 1].second += bb[l].second;
                    ++l;
                } else {
                    bb[l].first += (k / bb[l].second);
                    k = 0;
                }
            } else if ((bb[l + 1].first - bb[l].first) > (bb[r].first - bb[r - 1].first)){
                if (k >= (bb[r].first - bb[r - 1].first) * bb[r].second) {
                    k -= (bb[r].first - bb[r - 1].first) * bb[r].second;
                    bb[r - 1].second += bb[r].second;
                    --r;
                } else {
                    bb[r].first -= (k / bb[r].second);
                    k = 0;
                }
            } else {
                if (k >= (bb[l + 1].first - bb[l].first) * bb[l].second) {
                    k -= (bb[l + 1].first - bb[l].first) * bb[l].second;
                    bb[l + 1].second += bb[l].second;
                    ++l;
                } else {
                    bb[l].first += (k / bb[l].second);
                    k = 0;
                }
            }
        }
    }
    cout << bb[r].first - bb[l].first;
}