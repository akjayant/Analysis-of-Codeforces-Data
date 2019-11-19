#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cmath>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <deque>
#include <cassert>
#include <numeric>
using namespace std;
#define kekek ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int maxn = 1e5 + 5;
bitset<maxn> used;
int ans = 0;
set<int> not_used;
vector<set<int>> g;

void dfs(int v) {
    used[v] = 1;
    set<int> kek;

    while (!not_used.empty()) {
        int u = *not_used.begin();
        if (v != u && g[v].count(u) == 0) {
            not_used.erase(u);

            for (auto z : kek) {
                not_used.insert(z);
            }

            dfs(u);
            for (auto z : kek) {
                if (not_used.count(z) == 1) {
                    not_used.erase(z);
                }
            }
        }
        else {
            kek.insert(u);
            not_used.erase(u);
        }
    }

    for (auto z : kek) {
        not_used.insert(z);
    }
}

signed main() {
    kekek;
    
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    for (int i = 1; i <= n; i++) {
        not_used.insert(i);
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            ans++;
            dfs(i);
        }
    }

    cout << ans - 1;

    //system("pause");
    return 0;
}