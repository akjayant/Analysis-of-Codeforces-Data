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
using std::min;
const int N = 2e5+10;
const int mod = 1e9+7;
char ch[N];
int sum[3], a[3];
int n;
#define ll long long
int res[N];
int main() {
//    freopen("mytestdata.in", "r", stdin);
    int T; scanf("%d", &T);
    while (T--) {
        sum[0] = sum[1] = sum[2] = 0;
        scanf("%d", &n); int k = ceil((double)n/2.0);
        scanf("%d%d%d", &a[0], &a[2], &a[1]);
        scanf("%s", ch);
        int ans = 0;
            for (int i=0; i<n; i++) {
                res[i] = -1;
            }
            for (int i=0; i<n; i++) {
                if (ch[i] == 'R' && a[2]) {
                    res[i] = 2; --a[2]; ++ans;
                } else if (ch[i]=='S' && a[0]){
                    res[i] = 0; --a[0]; ++ans;
                } else if (ch[i]=='P' && a[1]) {
                    res[i] = 1; --a[1]; ++ans;
                }
            }
            for (int i=0; i<n; i++) {
                if (res[i] == -1) {
                    if (a[0]) {
                        res[i] = 0; --a[0];
                    } else if (a[1]) {
                        res[i] = 1; --a[1];
                    } else res[i] = 2, --a[2];
                }
            }
        if (ans >= k) {
            printf("YES\n");
            for (int i=0; i<n; i++) {
                if (res[i]==0) printf("R");
                else if (res[i]==1) printf("S");
                else printf("P");
            }
            printf("\n");
        } else printf("NO\n");
    }
    return 0;
}
