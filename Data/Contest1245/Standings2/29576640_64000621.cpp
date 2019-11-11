//
//  !CF20191101.cpp
//  National Olympiad in Informatics in Provinces
//
//  Created by 黄子齐 on 2019/11/1.
//  Copyright © 2019 黄子齐. All rights reserved.
//

#include <stdio.h>
#include <string.h>
const int N = 2e5+10;
const int mod = 1e9+7;
int fib[N];
char ch[N];
#define ll long long
int main() {
//    freopen("mytestdata.in", "r", stdin);
    scanf("%s", ch);
    int n = strlen(ch);
    fib[0] = fib[1] = 1;
    for (int i=2; i<=n; i++) {
        fib[i] = (fib[i-1]+fib[i-2])%mod;
    }
    ll ans = 1;
    for (int i=0; i<n; i++) {
        if (ch[i] == 'm' || ch[i] == 'w') {
            printf("0\n"); return 0;
        }
        if (ch[i] == 'n') {
            int ns = 0;
            while (ch[i] == 'n') {
                ++i; ++ns;
            }
            --i;
            ans = ans*fib[ns]%mod;
            continue;
        }
        if (ch[i] == 'u') {
            int ns = 0;
            while (ch[i] == 'u') {
                ++i; ++ns;
            }
            --i;
            ans = ans*fib[ns]%mod;
            continue;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
