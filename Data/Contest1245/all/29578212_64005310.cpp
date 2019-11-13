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

const int maxn = 105;
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

int a, b, c;
int n;
char s[maxn];
int res[maxn];

int main(int argc, char* argv[]) {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%d%d%d%d", &n, &a, &b, &c);
        scanf("%s", s + 1);
        int at = 0, bt = 0, ct = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'R') at ++;
            else if (s[i] == 'S') ct ++;
            else bt ++;
        }
        int need = (n + 1) / 2;
        int can = min(a, ct) + min(b, at) + min(c, bt);
        if (can < need) puts("NO");
        else {
            puts("YES");
            int hasa = min(a, ct);
            int hasb = min(b, at);
            int hasc = min(c, bt);
            int resta = a - hasa;
            int restb = b - hasb;
            int restc = c - hasc;
            for (int i = 1; i <= n; ++i) {
                if (s[i] == 'R') {
                    if (hasb) putchar('P'), hasb--;
                    else {
                        if (resta) putchar('R'), resta --;
                        else if (restc) putchar('S'), restc --;
                    }
                } else if (s[i] == 'S') {
                    if (hasa) putchar('R'), hasa --;
                    else {
                        if (restb) putchar('P'), restb --;
                        else if (restc) putchar('S'), restc --;
                    }
                } else {
                    if (hasc) putchar('S'), hasc --;
                    else {
                        if (resta) putchar('R'), resta --;
                        else if (restb) putchar('P'), restb --;
                    }
                }
            }
            puts("");
        }
    }
    return 0;
}