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

i64 T;
map<char, char> q = {
        {'R', 'P'},
        {'S', 'R'},
        {'P', 'S'},
};
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::fixed);

    cin >> T;

    for (i64 tt = 0; tt < T; tt++) {
        i64 n;
        i64 a, b, c;
        string s;

        cin >> n;
        cin >> a >> b >> c;
        cin >> s;

        map<char, i64> z;
        z['R'] = a;
        z['P'] = b;
        z['S'] = c;

        stringstream ss;
        for (i64 i = 0; i < s.size(); i++) {
            ss << '-';
        }

        string r = ss.str();
        i64 R = 0;

        for (i64 i = 0; i < s.size(); i++) {
            char t = q[s[i]];
            if (z[t] > 0) {
                r[i] = t;
                z[t]--;
                R++;
            }
        }

        for (i64 i = 0; i < s.size(); i++) {
            if (r[i] != '-') {
                continue;
            }
            for (auto& t : z) {
                if (t.second == 0) {
                    continue;
                }
                r[i] = t.first;
                t.second--;
                break;
            }
        }

        i64 Q = n / 2 + (n % 2 ? 1 : 0);
        if (R >= Q) {
            cout << "YES" << endl;
            cout << r << endl;
        } else {
            cout << "NO" << endl;
//            cerr << r << endl;

        }
    }

    return 0;
}
