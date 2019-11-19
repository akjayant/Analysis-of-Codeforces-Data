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

i64 t;
i64 n;
string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::fixed);

    cin >> t;
    for (i64 i = 0; i < t; i++) {
        cin >> n >> s;

        i64 R = n;
        for (i64 j = 1; j <= n; j++) {
            if (s[j - 1] == '0') {
                continue;
            }
            i64 w = 2 * max(j, n - j + 1);
            R = max(R, w);
        }
        cout << R << endl;
    }

    return 0;
}