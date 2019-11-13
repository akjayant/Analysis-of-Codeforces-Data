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

const i64 MAXN = 300005;

string s;

i64 dp[MAXN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::fixed);

    cin >> s;

    dp[0] = 1;
    dp[1] = 1;
    for (i64 i = 2; i <= s.size(); i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mod;
    }

    i64 R = 1;
    char p = '-';
    i64 q = 1;
    for (i64 i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == 'w' || c == 'm') {
            cout << 0 << endl;
            return 0;
        }
        if (c == p) {
            q++;
        } else {
            if (p == 'u' || p == 'n') {
                R *= dp[q];
                R %= mod;
            }
            q = 1;
            p = c;
        }
    }

    if (p == 'u' || p == 'n') {
        R *= dp[q];
        R %= mod;
    }

    cout << R << endl;

    return 0;
}
