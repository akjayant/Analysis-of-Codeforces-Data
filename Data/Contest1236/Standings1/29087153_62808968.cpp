#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 100005;

vector <int> mas[maxn];
vector <int> sto[maxn];
map <pair <int, int>, bool> ma;
int ans;
int n, m, k;

void fun(int lx, int rx, int ly, int ry, int f) {
    ly++;
    if (lx > rx || ly > ry) {
        return;
    }
    if (ma[{lx, ly}]) {
        return;
    }
    ans++;
    f = 0;
    int curx = lx, cury = ly;
    if (ans == n * m - k) {
        cout << "Yes";
        exit(0);
    }
    if (upper_bound(mas[curx].begin(), mas[curx].end(), cury) == mas[curx].end()) {
        cury = ry;
    } else {
        cury = min(ry, *upper_bound(mas[curx].begin(), mas[curx].end(), cury) - 1);
    }
    if (cury == ly)
        f++;

    if (f == 2) {
        return;
    } else {
        if (cury == ly) {
            f = 1;
        } else {
            f = 1;
        }
    }

    ans += cury - ly;
    if (ans == n * m - k) {
        cout << "Yes";
        exit(0);
    }

    if (upper_bound(sto[cury].begin(), sto[cury].end(), curx) == sto[cury].end()) {
        curx = rx;
    } else {
        curx = min(rx, *upper_bound(sto[cury].begin(), sto[cury].end(), curx) - 1);
    }
    if (curx == lx)
        f++;
    if (f == 2) {
        return;
    } else {
        if (curx == lx) {
            f = 1;
        } else {
            f = 1;
        }
    }

    ans += curx - lx;
    if (ans == n * m - k) {
        cout << "Yes";
        exit(0);
    }

    int ax = curx, ay = cury;
    int a = lower_bound(mas[curx].begin(), mas[curx].end(), cury) - mas[curx].begin() - 1;
    if (a < 0) {
        cury = ly;
    } else {
        cury = max(ly, mas[curx][a] + 1);
    }
    if (cury == ay) {
        f++;
    }
    if (f == 2) {
        return;
    } else {
        if (cury == ay) {
            f = 1;
        } else {
            f = 1;
        }
    }

    ans += ay - cury;
    if (ans == n * m - k) {
        cout << "Yes";
        exit(0);
    }

    a = lower_bound(sto[cury].begin(), sto[cury].end(), curx) - sto[cury].begin() - 1;
    if (a < 0) {
        curx = lx + 1;
    } else {
        curx = max(lx + 1, sto[cury][a] + 1);
    }
    if (curx == ax) {
        f++;
    }
    if (f == 2) {
        return;
    }
    if (curx == ax){
        f = 1;
    } else {
        f = 1;
    }

    ans += ax - curx;
    if (ans == n * m - k) {
        cout << "Yes";
        exit(0);
    }

    fun(curx, ax - 1, cury, ay - 1, f);
}

signed main() {
    int a, b, c, d, e, f, g, h, i, j;
    int x, y, t, q, l, r, p, z;
    string s = "";

    cin >> n >> m >> k;
    for (i = 0; i < k; i++) {
        cin >> a >> b;
        mas[a].push_back(b);
        sto[b].push_back(a);
        ma[{a, b}] = true;
    }
    for (i = 1; i <= n; i++) {
        sort(mas[i].begin(), mas[i].end());
    }
    for (i = 1; i <= m; i++) {
        sort(sto[i].begin(), sto[i].end());
    }
    ans = 0;
    fun(1, n, 0, m, 0);
    if (ans == n * m - k) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
