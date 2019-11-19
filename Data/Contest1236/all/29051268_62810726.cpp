#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define F(i, n) for(int i = 0; i < n; ++ i)

int n, m, k;
vector<vector<int> > v, d;
set<int> sv, sd;

int GetRight(int i, int j) {
    int pos = *upper_bound(v[i].begin(), v[i].end(), j);
    auto it0 = sv.upper_bound(j);
    return min(pos - 1, *it0 - 1);
}

int GetLeft(int i, int j) {
    auto it = lower_bound(v[i].begin(), v[i].end(), j);
    auto it0 = sv.lower_bound(j);
    -- it0;
    -- it;
    return max(*it + 1, *it0 + 1);
}

int GetBottom(int i, int j) {
    int pos = *upper_bound(d[j].begin(), d[j].end(), i);
    auto it0 = sd.upper_bound(i);
    return min(pos - 1, *it0 - 1);
}

int GetTop(int i, int j) {
    auto it = lower_bound(d[j].begin(), d[j].end(), i);
    auto it0 = sd.lower_bound(i);
    -- it0;
    -- it;
    return max(*it + 1, *it0 + 1);
}

struct Position {
    Position() {}
    Position(int i, int j, int dir) : i(i), j(j), dir(dir) {}
    int i, j, dir;

    Position NextPos() {
        Position next_pos = *this;
        if (dir == 0) {
            next_pos.j = GetRight(i, j);
        }
        if (dir == 1) {
            next_pos.i = GetBottom(i, j);
        }
        if (dir == 2) {
            next_pos.j = GetLeft(i, j);
        }
        if (dir == 3) {
            next_pos.i = GetTop(i, j);
        }
        next_pos.dir = (dir + 1) % 4;
        return next_pos;
    }
};

int calc(Position pos) {
    int ans = 1;
    while(true) {
         //   cout << "point:\n";
         //   cout << pos.i << ' ' << pos.j << ' ' << pos.dir << endl;
        Position next_pos = pos.NextPos();
        //cout << "next point:\n";
       //     cout << next_pos.i << ' ' << next_pos.j << ' ' << next_pos.dir << endl;
        if(next_pos.i == pos.i && next_pos.j == pos.j) break;
        ans += abs(pos.i - next_pos.i) + abs(pos.j - next_pos.j);
        if(pos.i == next_pos.i) {
            sd.insert(pos.i);
        } else {
            sv.insert(pos.j);
        }
        pos = next_pos;
    }
    return ans;
}

void Reset() {
    sv.clear();
    sd.clear();
    sv.insert(0);
    sv.insert(m + 1);
    sd.insert(0);
    sd.insert(n + 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    v.resize(n + 2);
    d.resize(m + 2);
    Reset();
    F(e, k) {
        int i, j; cin >> i >> j;
        v[i].push_back(j);
        d[j].push_back(i);
    }
    for(int i = 1; i <= n; ++ i) {
        v[i].push_back(0);
        v[i].push_back(m + 1);
        sort(v[i].begin(), v[i].end());
    }
    for(int j = 1; j <= m; ++ j) {
        d[j].push_back(0);
        d[j].push_back(n + 1);
        sort(d[j].begin(), d[j].end());
    }
    int a = calc(Position(1, 1, 0));
    Reset();
    int b = calc(Position(1, 1, 1));
    //cout << a << endl << n * n - k << endl;

    if (a == n * m - k || b == n * m - k) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
