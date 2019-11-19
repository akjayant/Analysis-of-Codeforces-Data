#include <bits/stdc++.h>
#define x1 wehfbweb1
#define x2 wehfbweb2
#define y1 wehfbweb3
#define y2 wehfbweb4
using namespace std;
const long long MOD = 1e9 + 7;
const int maxn = 1e5 + 555;
int a, b;
set<pair<int, int>> V;
vector<int> row[maxn];
vector<int> col[maxn];
bool checked(int x1, int y1, int x2, int y2) {
    if (x1 <= x2 && y1 <= y2) {
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (!V.count(make_pair(i, j))) {
                    return false;
                }
            }
        }
        return true;
    } else {
        return true;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        row[a].push_back(b);
        col[b].push_back(a);
        V.insert(make_pair(a, b));
    }
    for (int i = 1; i <= 100000; i++) {
        sort(row[i].begin(), row[i].end());
        sort(col[i].begin(), col[i].end());
    }
    int x1 = 1, y1 = 1, x2 = n, y2 = m;
    while (x1 <= x2 && y1 <= y2) {
        // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

        // if (V.count(make_pair(x1, y1))) {
        //     cout << "No" << endl;
        //     return 0;
        // }

        int x = x1, y = y1;
        auto p1 = -1;
        for (auto i : row[x]) {
            if (i >= y1 && i <= y2) {
                p1 = i;
                break;
            }
        }
        if (p1 != -1) {
            if (checked(x1, p1, x2, y2)) {
                y = p1 - 1;
                y2 = y;
            } else {
                cout << "No" << endl;
                return 0;
            }
        } else {
            y = y2;
        }

        // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

        auto p2 = -1;
        for (auto i : col[y]) {
            if (i >= x1 && i <= x2) {
                p2 = i;
                break;
            }
        }
        if (p2 != -1) {
            if (checked(p2, y1, x2, y2)) {
                x = p2 - 1;
                x2 = x;
            } else {
                cout << "No" << endl;
                return 0;
            }
        } else {
            x = x2;
        }

        // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

        auto p3 = -1;
        for (int i = (int)row[x].size() - 1; i >= 0; i--) {
            int _i = row[x][i];
            if (_i >= y1 && _i <= y2) {
                p3 = _i;
                break;
            }
        }
        if (p3 != -1) {
            if (checked(x1 + 1, y1, x2, p3)) {
                y = p3 + 1;
                y1 = y;
            } else {
                cout << "No" << endl;
                return 0;
            }
        } else {
            y = y1;
        }

        // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

        auto p4 = -1;
        for (int i = (int)col[y].size() - 1; i >= 0; i--) {
            int _i = col[y][i];
            if (_i >= x1 + 1 && _i <= x2) {
                p4 = _i;
                break;
            }
        }
        if (p4 != -1) {
            if (checked(x1 + 1, y1, p4, y2 - 1)) {
                x = p4;
                x1 = x;
            } else {
                cout << "No" << endl;
                return 0;
            }
        } else {
            x = x1;
        }

        // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
        x1++;
        y1++;
        x2--;
        y2--;
    }
    cout << "Yes" << endl;
    return 0;
}