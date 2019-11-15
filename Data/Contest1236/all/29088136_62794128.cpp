/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*
*   创 建 者： badcw
*   创建日期： 2019-10-17 21:35:59
*
================================================================*/
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int maxn = 305;
const int mod = 1e9+7;
ll qp(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

template <class T>
inline bool scan(T& ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) return 0; // EOF
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}

//template <class T>
//inline void out(T x) {
//    if (x > 9) out(x / 10);
//    putchar(x % 10 + '0');
//}

int res[maxn][maxn];
int n;

int main(int argc, char* argv[]) {
    scanf("%d", &n);
    int now = n * n;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            for (int j = 1; j <= n; ++j) {
                res[j][i] = now--;
            }
        } else {
            for (int j = n; j >= 1; --j) {
                res[j][i] = now--;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d%c", res[i][j], j == n ? '\n' : ' ');
        }
    }
    return 0;
}