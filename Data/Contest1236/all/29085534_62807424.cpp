#include<bits/stdc++.h>
 
using namespace std;
const int inf = 1e9 + 7;
const int MAXN = 1e5 + 7;
long long n, m, k;
set<int> obs_x[MAXN];
set<int> obs_y[MAXN];
 
int main() {
    cout.precision(20);
    cout << fixed;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        obs_y[a].insert(b);
        obs_x[b].insert(a);
    }
    int x = 0;
    int y = 0;
    int stop_x_max = m;
    int stop_y_max = n;
    int stop_x_min = -1;
    int stop_y_min = 0;
    int dest = 1;
    long long cnt = 1;
    while (true) {
        if (dest == 1) {
            auto it = obs_y[y].upper_bound(x);
            if (it != obs_y[y].end() && *it < stop_x_max) stop_x_max = *it;
            if (x == stop_x_max - 1) break;
            cnt += (long long)(stop_x_max - x - 1);
            x = stop_x_max - 1;
            stop_x_max -= 1;
            dest += 1;
            continue;
        }
        if (dest == 2) {
            auto it = obs_x[x].upper_bound(y);
            if (it != obs_x[x].end() && *it < stop_y_max) stop_y_max = *it;
            if (y == stop_y_max - 1) break;
            cnt += (long long)(stop_y_max - y - 1);
            y = stop_y_max - 1;
            stop_y_max--;
            dest += 1;
            continue;
        }
        if (dest == 3) {
            auto it = obs_y[y].upper_bound(x);
            if (it != obs_y[y].begin()) {
                --it;
                if (*it > stop_x_min) stop_x_min = *it;
            }
            if (x == stop_x_min + 1) break;
            cnt += (long long)(x - stop_x_min - 1);
            x = stop_x_min + 1;
            ++stop_x_min;
            dest = 0;
            continue;
        }
        if (dest == 0) {
            auto it = obs_x[x].upper_bound(y);
            if (it != obs_x[x].begin()) {
                --it;
                if (*it > stop_y_min) stop_y_min = *it;
            }
            if (y == stop_y_min + 1) break;
            cnt += (long long)(y - stop_y_min - 1);
            y = stop_y_min + 1;
            ++stop_y_min;
            dest = 1;
            continue;
        }
    }
    if (n * m - k <= cnt) cout << "Yes" << endl;
    else {
        x = 0;
        y = 0;
        cnt = 0;
        while (y < n && obs_x[0].find(y) == obs_x[0].end()) {
            ++cnt;
            ++y;
        }
        if (n * m - k <= cnt) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    }
    return 0;
}