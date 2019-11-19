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

const i64 MAXN = 300005;

i64 n, p, w, d;

i64 a[MAXN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::fixed);

    cin >> n >> p >> w >> d;



    const i64 bt = w - d;

    stringstream ss;
    bool f = false;

    //i64 min_k = p / d + (p % d ? 1 : 0);
    for (i64 k = min(n, p / d); 1; k--) {
        const i64 tp = k * w - p;
        if (tp < 0) {
            break;
        }
        i64 t = tp % bt;
        if (!t) {
            i64 y = tp / bt;
            if (k < y) {
                break;
            }
            i64 x = (p - y * d) / w;
            if (x < 0) {
                break;
            }
            i64 z = n - x - y;
            if (z < 0) {
                break;
            }
            ss << x << " " << y << " " << z << endl;
            f = true;
            break;
        }

        if (a[t]) {
            break;
        }
        else {
            a[t] = 1;
            continue;
        }
    }

    if (!f) {
        ss << -1 << endl;
    }
    cout << ss.str();


    return 0;
}