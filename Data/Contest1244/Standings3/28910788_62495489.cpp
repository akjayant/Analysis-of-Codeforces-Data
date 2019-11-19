#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define int long long


signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    deque<pair<int, int>> deq;
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        if (deq.empty() || deq.back().first != a[i]) {
            deq.emplace_back(a[i], 1);
        } else {
            deq.back().second++;
        }
    }
    while (k > 0 && deq.size() > 1) {
        if (deq.back().second < deq.front().second) {
            int alfa = k / deq.back().second;
            if (alfa == 0) {
                break;
            }
            auto kek = deq.back();
            deq.pop_back();
            if (abs(kek.first - deq.back().first) <= alfa) {
                k -= kek.second * abs(kek.first - deq.back().first);
                deq.back().second += kek.second;
            } else {
                k -= alfa * kek.second;
                kek.first -= alfa;
                deq.push_back(kek);
            }
        } else {
            int alfa = k / deq.front().second;
            if (alfa == 0) {
                break;
            }
            auto kek = deq.front();
            deq.pop_front();
            if (abs(kek.first - deq.front().first) <= alfa) {
                k -= kek.second * abs(kek.first - deq.front().first);
                deq.front().second += kek.second;
            } else {
                k -= alfa * kek.second;
                kek.first += alfa;
                deq.push_front(kek);
            }
        }
    }
    cout << deq.back().first - deq.front().first;
}
