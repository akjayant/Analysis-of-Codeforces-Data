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

const int maxn = 100;
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

//int mp[maxn];
//int lim;
//int n;
//int res;
//
//void dfs(int pos) {
//    if (pos == n) {
//        int k = 0;
//        for (int i = 0; i < n; ++i) {
//            k |= mp[i];
//        }
//        if (k == lim - 1) res ++;
//        return;
//    }
//    for (int i = 0; i < lim; ++i) {
//        mp[pos] = i;
//        dfs(pos + 1);
//    }
//}

ll n, m;

int main(int argc, char* argv[]) {
    scanf("%lld%lld", &n, &m);
    printf("%lld\n", qp((qp(2, m) - 1 + mod)%mod, n));
//    lim = 1 << 3;
//    n = 3;
//    res = 0;
//    dfs(0);
//    printf("%d\n", res);
    return 0;
}