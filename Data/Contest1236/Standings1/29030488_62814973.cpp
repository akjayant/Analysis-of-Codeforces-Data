#include <bits/stdc++.h>
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#define int long long

using namespace std;

mt19937 rnd(time(nullptr));

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    map <int, set <int> > all1, all2, all3, all4;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        all1[x].insert(y);
        all2[y].insert(x);
        all3[x].insert(-y);
        all4[y].insert(-x);
    }
    set <int> hor1, hor2, ver1, ver2;
    for (int i = 0; i < n; i++) {
        all1[i].insert(m);
        all3[i].insert(1);
    }
    for (int i = 0; i < m; i++) {
        all2[i].insert(n);
        all4[i].insert(1);
    }
    hor1.insert(n);
    hor2.insert(1);
    ver1.insert(m);
    ver2.insert(1);
    int x = 0, y = 0;
    int dir = 0;
    int sh = 0;
    int lol = n * m - k;
    while (true) {
        if (dir == 0) {
            int kek = min(*all1[x].upper_bound(y), *ver1.upper_bound(y));
            hor1.insert(x);
            hor2.insert(-x);
            //cout << kek << "aaa\n";
            if (kek - 1 == y && sh)
                break;
            lol -= (kek - y);
            if (sh)
                lol++;
            dir = 1;
            sh = 1;
            y = kek - 1;
        }
        else if (dir == 1) {
            int kek = min(*all2[y].upper_bound(x), *hor1.upper_bound(x));
            //cout << kek << "bbb\n";
            ver1.insert(y);
            ver2.insert(-y);
            if (kek - 1 == x)
                break;
            lol -= (kek - x);
            lol++;
            dir = 2;
            x = kek - 1;
        }
        else if (dir == 2) {
            int kek = max(-*all3[x].upper_bound(-y), -*ver2.upper_bound(-y));
            hor1.insert(x);
            hor2.insert(-x);
            if (kek + 1 == y)
                break;
            //cout << kek << "ccc\n";
            lol -= (y - kek);
            lol++;
            y = kek + 1;
            dir = 3;
        }
        else if (dir == 3) {
            int kek = max(-*all4[y].upper_bound(-x), -*hor2.upper_bound(-x));
            //cout << *ver2.upper_bound(-x) << "aaaaaaaaaaaaaaaaaaa\n";
            ver1.insert(y);
            ver2.insert(-y);
            if (kek + 1 == x)
                break;
            //cout << kek << "ddd\n";
            lol -= (x - kek);
            lol++;
            dir = 0;
            x = kek + 1;
        }
        //cout << lol << "vmfdi\n";
    }
    //cout << lol << "\n";
    if (!lol)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
