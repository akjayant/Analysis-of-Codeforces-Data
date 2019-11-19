#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

typedef long long int64;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

int a[MAXN];

#include <cctype>
#include <cstdio>

template <typename T = int>
inline T read() {
    T X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch)) {
        w |= ch == '-';
        ch = getchar();
    }
    while (isdigit(ch)) {
        X = (X << 3) + (X << 1) + (ch ^ 48);
        ch = getchar();
    }
    return w ? -X : X;
}

int main() {
    int n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    sort(a + 1, a + n + 1);
    int64 sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        if (i * 2 <= n) {
            sum1 += a[i];
        } else {
            sum2 += a[i];
        }
    }
    cout << sum1 * sum1 + sum2 * sum2 << endl;
}