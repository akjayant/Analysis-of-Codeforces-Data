//
//  !CF20191101.cpp
//  National Olympiad in Informatics in Provinces
//
//  Created by 黄子齐 on 2019/11/1.
//  Copyright © 2019 黄子齐. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using std::min;
const int N = 2e2+10;
#define ll long long
int l[N], r[N];
inline int binary(int x, int *a) {
    int cnt = 0;
    while (x) {
        a[cnt++] = x&1;
        x >>= 1;
    }
    for (int i=cnt; i<=100; i++) {
        a[i] = 0;
    }
    return cnt;
}
int L, R, n;
ll f[N][2][2];
inline void dp(int L, int R) {
    memset(f, 0, sizeof(f));
//    printf("cnm:%lld\n", f[n][0][0]);
    if (!L || !R) return;
    f[n][1][1] = 1;
    for (int i=n-1; i>=0; i--) {
//        printf("%d %d\n", l[i], r[i]);
//        printf("%d %lld %lld %lld %lld\n", i, f[i+1][0][0], f[i+1][0][1], f[i+1][1][0], f[i+1][1][1]);
        if (l[i]) {
            if (r[i]) {
                f[i][0][0] = f[i+1][0][1]*2+f[i+1][1][0]*2+f[i+1][1][1]+f[i+1][0][0]*3;
                f[i][0][1] = f[i+1][0][1]+f[i+1][1][1];
                f[i][1][0] = f[i+1][1][0]+f[i+1][1][1];
            } else {
                f[i][0][0] = f[i+1][0][0]*3+f[i+1][1][0]*2;
                f[i][0][1] = f[i+1][0][1]*2+f[i+1][1][1];
                f[i][1][0] = f[i+1][1][0];
                f[i][1][1] = f[i+1][1][1];
            }
        } else {
            if (r[i]) {
                f[i][0][0] = f[i+1][0][0]*3+f[i+1][0][1]*2;
                f[i][0][1] = f[i+1][0][1];
                f[i][1][0] = f[i+1][1][0]*2+f[i+1][1][1];
                f[i][1][1] = f[i+1][1][1];
            } else {
                f[i][0][0] = f[i+1][0][0]*3;
                f[i][0][1] = f[i+1][0][1]*2;
                f[i][1][0] = f[i+1][1][0]*2;
                f[i][1][1] = f[i+1][1][1];
            }
        }
//        printf("%d %lld %lld %lld %lld\n", i, f[i][0][0], f[i][0][1], f[i][1][0], f[i][1][1]);
    }
    f[0][0][0] -= L+R-1; f[0][0][1]--; f[0][1][0]--;
//    printf("%lld %lld %lld %lld\n", f[0][0][0], f[0][0][1], f[0][1][0], f[0][1][1]);
    return;
}
int main() {
//    freopen("mytestdata.in", "r", stdin);
    int T; scanf("%d", &T);
//    binary(2, l); binary(3, r); n=2; dp(2, 3);
    while (T--) {
        scanf("%d%d", &L, &R);
        if (!L && !R) {
            printf("1\n"); continue;
        }
        ll ans = 0;
        if (!L) {
            ans += R*2+1; ++L;
        }
        n = binary(R, r);
        binary(R, l);
        dp(R, R);
        ans += f[0][0][0]+f[0][0][1]+f[0][1][0]+f[0][1][1];
//        printf("%lld\n", ans);
        binary(L-1, l);
        dp(L-1, R);
        ans -= f[0][0][0]+f[0][0][1]+f[0][1][0]+f[0][1][1];
        ans -= f[0][0][0]+f[0][0][1]+f[0][1][0]+f[0][1][1];
//        printf("%lld\n", ans);
        n = binary(L-1, r);
        dp(L-1, L-1);
        ans += f[0][0][0]+f[0][0][1]+f[0][1][0]+f[0][1][1];
        printf("%lld\n", ans);
    }
    return 0;
}
