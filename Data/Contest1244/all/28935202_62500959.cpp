#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    i64 k;
    scanf("%d%lld", &n, &k);
    std::vector<i64> a(n);
    for (auto &e : a) scanf("%lld", &e);
    std::sort(a.begin(), a.end());

    i64 l = -1, r = 1000000100;
    while (r - l > 1) {
        i64 d = (l + r) / 2, rem = k;
        std::deque<std::pair<i64, i64>> v;
        for (auto e : a) {
            if (v.empty() || v.back().first != e) v.emplace_back(e, 1);
            else v.back().second++;
        }

        while (rem && v.size() > 1) {
            int m = v.size();
            if (v.front().second <= v.back().second) {
                i64 cnt = v.front().second;
                if (rem < cnt) break;
                i64 md = v[1].first - v[0].first;
                i64 cost = std::min(md * cnt, rem / cnt * cnt);
                if (cost == md * cnt) {
                    v[1].second += v[0].second;
                    v.pop_front();
                } else v[0].first += rem / cnt;
                rem -= cost;
            } else {
                i64 cnt = v.back().second;
                if (rem < cnt) break;
                i64 md = v[m - 1].first - v[m - 2].first;
                i64 cost = std::min(md * cnt, rem / cnt * cnt);
                if (cost == md * cnt) {
                    v[m - 2].second += v[m - 1].second;
                    v.pop_back();
                } else v[m - 1].first -= rem / cnt;
                rem -= cost;
            }
        }

        if (v.back().first - v.front().first <= d) r = d;
        else l = d;
    }

    printf("%lld\n", r);

    return 0;
}
