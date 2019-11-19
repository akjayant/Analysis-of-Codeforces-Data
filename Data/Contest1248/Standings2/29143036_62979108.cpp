#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <cassert>
#include <cmath>
using namespace std;

typedef long long int64;

const int INF = 0x3f3f3f3f;

#include <cctype>
#include <cstdio>

template <typename T = int>
inline T read() {
    T X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch))
    {
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
    int tcnt = read();
    for (int T = 1; T <= tcnt; T++) {
        int64 cntp_even = 0, cntp_odd = 0;
        int n = read();
        for (int i = 1; i <= n; i++) {
            int p = read();
            if (p % 2 == 0) {
                cntp_even++;
            } else {
                cntp_odd++;
            }
        }
        int64 cntq_even = 0, cntq_odd = 0;
        int m = read();
        for (int i = 1; i <= m; i++) {
            int q = read();
            if (q % 2 == 0) {
                cntq_even++;
            } else {
                cntq_odd++;
            }
        }
        cout << cntp_odd * cntq_odd + cntp_even * cntq_even << endl;
    }
}