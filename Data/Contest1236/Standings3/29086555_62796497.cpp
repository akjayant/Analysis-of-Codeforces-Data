#include<bits/stdc++.h>

const int MAXN = 1e3;

int fz[MAXN][MAXN], cnt;

int main() {
    int n;
    scanf("%d", &n);
    cnt = n * n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            fz[j][i] = cnt--;
        }
        i++;
        if(i > n) break;
        for(int j = n; j >= 1; j--) {
            fz[j][i] = cnt--;
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            printf("%d%c", fz[i][j], " \n"[j == n]);
    return 0;
}
