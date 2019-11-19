//
//  Alice and the Doll.cpp
//  National Olympiad in Informatics in Provinces
//
//  Created by 黄子齐 on 2019/10/17.
//  Copyright © 2019 黄子齐. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
const int N = 1e5+10;
set<int> s[2][N];
int n, m, k;
int fx[4] = {0, 1, 0, -1}, fy[4] = {1, 0, -1, 0};
int minw[4];
int main() {
    //freopen("mytestdata.in", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1; i<=k; i++) {
        int x, y; scanf("%d%d", &x, &y);
        s[0][x].insert(y); s[1][y].insert(x);
    }
    for (int i=1; i<=n; i++) {
        s[0][i].insert(0); s[0][i].insert(m+1);
    }
    for (int i=1; i<=m; i++) {
        s[1][i].insert(0); s[1][i].insert(n+1);
    }
    minw[1] = m+1; minw[2] = n+1; minw[0] = minw[3] = 0;
    int nx = 1, ny = 1, fi = 0;
//    printf("%d\n", fi);
    long long sum = 1;
    while (1) {
        int fn = (fi+1)%4;
        if (fi == 0) {
            //printf("%d %d\n", *s[0][nx].upper_bound(ny), minw[fn]);
            int wy = min(*s[0][nx].upper_bound(ny), minw[fn])-1;
            //printf("%d %d %d\n", nx, ny, wy);
            if (wy == ny && (nx!=1||ny!=1)) {
                break;
            }
            sum += wy-ny; minw[0] = nx; ny = wy;
        }
        if (fi == 1) {
            int wx = min(*s[1][ny].upper_bound(nx), minw[fn])-1;
            //printf("%d %d %d\n", nx, ny, wx);
            if (wx == nx) {
                break;
            }
            sum += wx-nx; minw[1] = ny; nx = wx;
        }
        if (fi == 2) {
            int wy = max(*(--s[0][nx].lower_bound(ny)), minw[fn])+1;
            //printf("%d %d %d\n", nx, ny, wy);
            if (wy == ny) {
                break;
            }
            sum += ny-wy; minw[2] = nx; ny = wy;
        }
        if (fi == 3) {
            int wx = max(*(--s[1][ny].lower_bound(nx)), minw[fn])+1;
            //printf("%d %d %d\n", nx, ny, wx);
            if (wx == nx) {
                break;
            }
            sum += nx-wx; minw[3] = ny; nx = wx;
        }
        //printf("fi:%d\n", fi);
        fi = fn;
    }
    if (sum == 1ll*n*m-k) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
