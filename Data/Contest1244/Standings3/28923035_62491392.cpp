#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdint.h>
#include <string.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

#include <algorithm>
#include <functional>
#include <bitset>
#include <functional>
#include <chrono>
#include <random>

#define sqr(x) (x) * (x)

typedef unsigned int u32;
typedef int i32;
typedef unsigned long long int u64;
typedef long long int i64;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint8_t u8;
typedef int8_t i8;

using namespace std;
using namespace std::chrono;

const i64 mod = 1000000007ll;
const i64 smod = 998244353ll;
const i64 inf = 10000000000000007ll;

const double eps = 1e-10;

// del

const i64 MAXN = 100005;

i64 n;

set<i64> e[MAXN];

i64 c[4][MAXN];

vector<i64> path;

i64 R[MAXN];

void gen_path(i64 S) {
    set<i64> u;
    
    while (1) {
        path.push_back(S);
        u.insert(S);

        bool f = false;
        for (auto t : e[S]) {
            if (u.find(t) == u.end()) {
                S = t;
                f = true;
                break;
            }
        }

        if (!f) {
            break;
        }
    }
}

map<pair<i64, i64>, i64> q = {
    { { 1, 2 }, 3 },
    { { 2, 1 }, 3 },
    { { 1, 3 }, 2 },
    { { 3, 1 }, 2 },
    { { 2, 3 }, 1 },
    { { 3, 2 }, 1 }
};


i64 solve() {
    i64 res = 0;
    for (i64 i = 1; i <= n; i++) {
        res += c[R[i]][i];
    }
    return res;
}

i64 gen_sol(pair<i64, i64> p) {
    R[path[0]] = p.first;
    R[path[1]] = p.second;

    for (i64 i = 2; i < n; i++) {
        pair<i64, i64> k = { R[path[i - 1]], R[path[i - 2]] };
        R[path[i]] = q[k];
    }

    return solve();
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::fixed);

    cin >> n;

    for (i64 j = 1; j <= 3; j++) {
        for (i64 i = 1; i <= n; i++) {
            cin >> c[j][i];
        }
    }

    for (i64 i = 1; i < n; i++) {
        i64 u, w;
        cin >> u >> w;
        e[u].insert(w);
        e[w].insert(u);
    }

    i64 S = 0;
    for (i64 i = 1; i <= n; i++) {
        if (e[i].size() > 2) {
            cout << -1 << endl;
            return 0;
        }
        if (e[i].size() == 1) {
            S = i;
        }
    }

    gen_path(S);
    //for (auto t : path) {
    //    cout << t << " ";
    //}

    pair<i64, i64> bres = { -1, -1 };
    i64 res = -1;

    for (auto t : q) {
        i64 w = gen_sol(t.first);

        if (res == -1 || w < res) {
            res = w;
            bres = t.first;
        }
    }

    i64 RR = gen_sol(bres);
    cout << RR << endl;
    for (i64 i = 1; i <= n; i++) {
        cout << R[i] << " ";
    }

    return 0;
}