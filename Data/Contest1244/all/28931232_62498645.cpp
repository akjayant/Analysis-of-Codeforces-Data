#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)

int debug = 0;

const int N = 7e5;
int n, k, it, m;
int a[N], ans[N], was[N];
array <int, 2> ev[N];

bool check_same() {
    int flag = 1;
    rep(i, 0, n) {
        if (a[i] != a[0]) {
            flag = 0;
        }
    }
    return flag;
}

main() {
    string s;
    cin >> n >> k >> s;
    rep(i, 0, n) {
        a[i] = a[i + n] = a[i + 2 * n] = int(s[i] == 'B');
    }
    int cur = 1, l = 0;
    vector <array <int, 3>> seg;
    rep(i, 1, 3 * n) {
        if (a[i] == a[i - 1]) {
            cur++;
        } else {
            if (cur > 1) {
                seg.push_back({l, i - 1, a[i - 1]});
                ev[l] = {a[i - 1], +1};
                ev[i - 1] = {a[i - 1], -1};
            }
            cur = 1;
            l = i;
        }
    }
    if (check_same()) {
        cout << s;
        return 0;
    }
    if (debug) {
        for (auto i : seg) {
            cerr << "     seg = " << i[0] << ' ' << i[1] << "  " << i[2] << '\n';
        }
        cerr << '\n';
    }
    it = 0;
    m = seg.size();
    rep(x, 0, 3 * n) {
        int xx = x % n;
        while (it < m && seg[it][1] < x) {
            ++it;
        }
        assert(it == m || x <= seg[it][1]);
        if (debug) {
            cerr << "  it=" << it << "   x=" << x << '\n';
        }
        if (it == m) {
            break; /// all positions will be colored?;
        }
        if (seg[it][0] <= x && x <= seg[it][1]) {
            ans[xx] = seg[it][2]; /// = color in seg
            was[xx] = 1;
        } else if (it == 0) {
            continue; /// will colored after?
        } else if (seg[it - 1][2] == seg[it][2]) { /// between same colors
            int L, R, color;
            assert(it > 0 && it < m);
            R = seg[it - 1][1];
            L = seg[it][0];
            color = seg[it][2];
            assert((L - R) % 2 == 0);
            if (x <= R + k || x >= L - k) {
                ans[xx] = color;
            } else {
                ans[xx] = ((x - (R + k)) % 2) ^ color;
            }
            was[xx] = 1;
        } else { /// it > 0 && it < m
            int L, R, Lcolor, Rcolor;
            assert(it > 0 && it < m);
            R = seg[it - 1][1];
            L = seg[it][0];
            Rcolor = seg[it - 1][2];
            Lcolor = seg[it][2];
            assert((L - R) % 2 == 1);
            if (x <= R + k && x >= L - k) {
                ans[xx] = (x - R < L - x) ? Rcolor : Lcolor;
            } else if (x <= R + k) {
                ans[xx] = Rcolor;
            } else if (x >= L - k) {
                ans[xx] = Lcolor;
            } else {
                ans[xx] = ((x - (R + k)) % 2) ^ Rcolor;
            }
            was[xx] = 1;
        }
    }
    if (seg.size() == 0) {
        k %= 2;
        rep(i, 0, n) {
            ans[i] = a[i] ^ k;
            was[i] = 1;
        }
    }
    rep(i, 0, n) {
        assert(was[i] == 1);
    }
    rep(i, 0, n) {
        cout << (ans[i] ? 'B' : 'W');
    }
}

/**
9 2
BBWBWBBWW
*/