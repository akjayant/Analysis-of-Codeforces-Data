/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*
*   创 建 者： badcw
*   创建日期： 2019-11-01 22:35:15
*
================================================================*/
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int maxn = 1e5+50;
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

char s[maxn];
ll fib[maxn] = {1, 1};

int main(int argc, char* argv[]) {
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 2; i <= len; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }
    for (int i = 0; i < len; ++i) {
        if (s[i] == 'm' || s[i] == 'w') {
            return !printf("0\n");
        }
    }
    ll res = 1;
    int pre = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == 'u') {
            pre ++;
        } else {
            res = (res * fib[pre]) % mod;
            pre = 0;
        }
    }
    res = (res * fib[pre]) % mod;
    pre = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == 'n') {
            pre ++;
        } else {
            res = (res * fib[pre]) % mod;
            pre = 0;
        }
    }
    res = (res * fib[pre]) % mod;
    printf("%lld\n", res);
    return 0;
}