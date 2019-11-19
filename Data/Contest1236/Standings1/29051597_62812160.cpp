#include <bits/stdc++.h>
#define N ((int)1e5+20)
#define MD ((int)1e9+7)

using namespace std;


vector<int> r[N], c[N];

int get_next(vector<int> &v, int y) {
    if (v.size() == 0)
        return 1e9;
    int ny = upper_bound(v.begin(), v.end(), y) - v.begin();
    if (ny >= 0 && ny < v.size()) {
        return v[ny] - 1;
    }
    return 1e9;
}

int get_prev(vector<int> &v, int y) {
    if (v.size() == 0)
        return 0;
    int ny = upper_bound(v.begin(), v.end(), y) - v.begin();
    ny--;
    if (ny >= 0 && ny < v.size()) {
        return v[ny] + 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int xt, yt;
        cin >> xt >> yt;
        r[xt].push_back(yt);
        c[yt].push_back(xt);
    }
    for (int i = 1; i <= 100000; i++) {
        if (r[i].size() > 1) {
            sort(r[i].begin(), r[i].end());
        }
        if (c[i].size() > 1) {
            sort(c[i].begin(), c[i].end());
        }
    }

    int x = 1, y = 1;
    int mxy = m;
    int mxx = n;
    int mny = 1;
    int mnx = 1;
    int dir = 0;
    long long sum = 1;
    set<pair<int, int> > p;
    for (int i = 0; i <= 400000; i++) {
        if (dir == 0) {
            int yy = get_next(r[x], y);
            yy = min(yy, mxy);
            if (yy - y > 0)
                sum += yy - y;
            y = yy;
            mnx = x + 1;
        } else if (dir == 1) {
            int xx = get_next(c[y], x);
            xx = min(xx, mxx);
            if (xx - x > 0)
                sum += xx - x;
            x = xx;
            mxy = y - 1;
        } else if (dir == 2) {
            int yy = get_prev(r[x], y);
            yy = max(yy, mny);
            if (y - yy > 0)
                sum += y - yy;
            y = yy;
            mxx = x - 1;
        } else {
            int xx = get_prev(c[y], x);
            xx = max(xx, mnx);
            if (x - xx > 0)
                sum += x - xx;
            x = xx;
            mny = y + 1;
        }
        dir++;
        dir %= 4;
        if (p.count(make_pair(x, y)))
            break;
        p.insert(make_pair(x, y));
    }
    if (sum + k == 1LL * n * m) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
