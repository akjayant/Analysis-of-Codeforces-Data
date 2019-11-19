#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

using namespace std;
typedef long long int lli;
typedef long double ld;

const int MAXN = 100005;
set<int> fx[MAXN];
set<int> fy[MAXN];
int dir = 1;
int gbX = 1;
int gbY = 1;
int mnX, mxX, mnY, mxY;

void change_dir() {
    ++dir;
    if (dir == 5) {
        dir = 1;
    }
}

int dist_next(int coord, set<int> &s, int lim) {
    auto t = s.upper_bound(coord);
    int mx = (t != s.end()) ? *t : lim;
    return min(mx, lim) - coord - 1;
}

int dist_prev(int coord, set<int> &s, int lim) {
    auto t = s.lower_bound(coord);
    int mn = (t != s.begin()) ? *(--t) : lim;
    return coord - max(mn, lim) - 1;
}

int go_max() {
    int d = 0;
    switch (dir) {
        case 1: {
            d = dist_next(gbY, fx[gbX], mxY);
            gbY += d;
            mxY = gbY;
            break;
        }
        case 2: {
            d = dist_next(gbX, fy[gbY], mxX);
            gbX += d;
            mxX = gbX;
            break;
        }
        case 3: {
            d = dist_prev(gbY, fx[gbX], mnY);
            gbY -= d;
            mnY = gbY;
            break;
        }
        case 4: {
            d = dist_prev(gbX, fy[gbY], mnX);
            gbX -= d;
            mnX = gbX;
            break;
        }
    }
    return d;
}

int main() {
    // ifstream cin("biconv.in");
    // ofstream cout("biconv.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        fx[x].insert(y);
        fy[y].insert(x);
    }
    mnX = 1;
    mxX = n + 1;
    mnY = 0;
    mxY = m + 1;
    dir = 1;
    lli ans = 1;
    bool f = true;
    while (true) {
        int r = go_max();
        if (!f && r == 0) {
            break;
        }
        f = false;
        ans += r;
        change_dir();
    }
    lli e = n;
    e *= m;
    if (ans == e - k) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}