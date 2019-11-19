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
#include <deque>
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
const i64 inf = 1000000000000007ll;

const double eps = 1e-10;

const i64 MAXN = 2003;

i64 n;

i64 x[MAXN];
i64 y[MAXN];

i64 c[MAXN];
i64 k[MAXN];

i64 z[MAXN][MAXN];

pair<i64, i64> g[MAXN];
i64 u[MAXN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::fixed);

    cin >> n;

    for (i64 i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    for (i64 i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (i64 i = 1; i <= n; i++) {
        cin >> k[i];
    }

    for (i64 i = 1; i <= n; i++) {
        g[i] = {inf, -1};
    }

    for (i64 i = 1; i <= n; i++) {
        for (i64 j = i + 1; j <= n; j++) {
            z[i][j] = z[j][i] = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
        }
    }

    i64 Rv = 0;
    set<i64> Rs;
    set<pair<i64, i64>> Rc;

    for (i64 tt = 1; tt<= n; tt++) {
        i64 e = inf;
        i64 j = -1;

        for (i64 i = 1; i <= n; i++) {
            if (u[i]) {
                continue;
            }
            if (e > c[i]) {
                e = c[i];
                j = i;
            }
        }


        i64 k = - 1;
        for (i64 i = 1; i <= n; i++) {
            if (u[i]) {
                continue;
            }
            if (e > g[i].first) {
                e = g[i].first;
                j = i;
                k = g[i].second;
            }
        }

        if (k == -1) {
            Rs.insert(j);
        } else {
            Rc.insert({j, k});
        }
        Rv += e;

        u[j] = 1;

        for (i64 i = 1; i <= n; i++) {
            if (u[i]) {
                continue;
            }
            if (g[i].first > z[i][j]) {
                g[i].first = z[i][j];
                g[i].second = j;
            }
        }
    }

    stringstream ss;
    ss << Rv << endl;
    ss << Rs.size() << endl;
    for (auto t : Rs) {
        ss << t << " ";
    }
    ss << endl;
    ss << Rc.size() << endl;
    for (auto t : Rc) {
        ss << t.first << " " << t.second << endl;
    }
    cout << ss.str();

    return 0;
}
