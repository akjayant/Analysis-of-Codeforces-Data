#include <bits/stdc++.h>

using namespace std;
#define int long long
#define EPS 1e-6
#define mod 1000000007


int first_in_range(const vector<int> &vec, int l, int r) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] > l && vec[i] <= r) {
            return vec[i];
        }
    }
    return r;
}

int last_in_range(const vector<int> &vec, int l, int r) {
    for (int i = (int)(vec.size()) - 1; i >= 0; --i) {

        if (vec[i] >= l && vec[i] < r) {
            return vec[i];
        }
    }
    return l;
}


signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> vert(m + 1);
    vector<vector<int>> hori(n + 1);
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        hori[x].push_back(y);
        vert[y].push_back(x);
    }
    for (int j = 0; j < m + 1; ++j) {
        sort(vert[j].begin(), vert[j].end());
    }
    for (int j = 0; j < n + 1; ++j) {
        sort(hori[j].begin(), hori[j].end());
    }
    int x = 1, y = 0, d = 1;
    int up = 0;
    int left = 0;
    int down = n + 1;
    int right = m + 1;
    int cnt = 0;


    int lx = -1;
    int ly = -1;

    int l1x = -2;
    int l1y = -2;
    while (true) {
        l1x = lx;
        l1y = ly;
        lx = x;
        ly = y;
        if (l1x == lx && lx == x &&
            l1y == ly && ly == y) {
            break;
        }
        if (d == 1) {
            int y1 = first_in_range(hori[x], y, right);
            left = y;
            cnt += y1 - y - 1;
            y = y1 - 1;
        } else if (d == 2) {
            int x1 = first_in_range(vert[y], x, down);
            up = x;
            cnt += x1 - x - 1;
            x = x1 - 1;
        } else if (d == 3) {
            int y1 = last_in_range(hori[x], left, y);
            right = y;
            cnt += y - y1 - 1;
            y = y1 + 1;
        } else {
            int x1 = last_in_range(vert[y], up, x);
            down = x;
            cnt += x - x1 - 1;
            x = x1 + 1;
        }

        d = (d) % 4 + 1;
    }
    cout << (cnt + k == n * m ? "Yes" : "No");

}