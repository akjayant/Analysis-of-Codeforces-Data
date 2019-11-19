#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef arrias
    freopen("true.txt", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int rz = a[n - 1] - a[0];
    deque<pair<int,int>> cnt;
    int prev = -132;
    for (int i = 0; i < n; ++i) {
        if (a[i] != prev) {
            cnt.push_back({a[i], 1});
        }
        else {
            cnt.back().second++;
        }
        prev = a[i];
    }
    while (cnt.size() > 2 && k > 0) {
        if (cnt.front().second > k && cnt.back().second > k) break;
        if (cnt.front().second < cnt.back().second) {
            int d = min(k / cnt[0].second, (cnt[1].first - cnt[0].first));
            k -= d * cnt[0].second;
            rz -= d;
            cnt[0].first += d;
            if (cnt[0].first == cnt[1].first) {
                cnt[1].second += cnt[0].second;
                cnt.pop_front();
            }
        }
        else {
            int d = min(k / cnt.back().second, (cnt.back().first - cnt[cnt.size() - 2].first));
            k -= d * cnt.back().second;
            rz -= d;
            cnt.back().first -= d;
            if (cnt.back().first == cnt[cnt.size() - 2].first) {
                cnt[cnt.size() - 2].second += cnt.back().second;
                cnt.pop_back();
            }
        }
    }
    if (cnt.size() == 2) {
        int d = cnt[1].first - cnt[0].first;
        int t = min(d, k / min(cnt[1].second, cnt[0].second));
        rz -= t;
    }
    cout << rz << "\n";
    return 0;
}
