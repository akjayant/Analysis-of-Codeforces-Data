#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 10;
const int mod = 1000000000 + 7;
int a[maxn][maxn];
int main() {
    int n;  scanf("%d", &n);
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
        if (j & 1) {
            for (int i = 1; i <= n; i++) {
                a[i][j] = ++cnt;
            }
        }
        else {
            for (int i = n; i >= 1; i--) {
                a[i][j] = ++cnt;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d%c", a[i][j], j < n ? ' ' : '\n');
        }
    }
    // cout << '\n';
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         int t = 0;
    //         for (int ii = 1; ii <= n; ii++) {
    //             for (int jj = 1; jj <= n; jj++) {
    //                 if (a[i][ii] > a[j][jj]) {
    //                     t++;
    //                 }
    //             }
    //         }
    //         cout << t << ' ';
    //     }cout << '\n';
    // }
    getchar(); getchar();
    return 0;
}