//
//  !CF20191101.cpp
//  National Olympiad in Informatics in Provinces
//
//  Created by 黄子齐 on 2019/11/1.
//  Copyright © 2019 黄子齐. All rights reserved.
//

#include <stdio.h>
int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x%y);
}
int n, m, T;
int main() {
//    freopen("mytestdata.in", "r", stdin);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        if (gcd(n, m) == 1) {
            printf("Finite\n");
        } else {
            printf("Infinite\n");
        }
    }
    return 0;
}
