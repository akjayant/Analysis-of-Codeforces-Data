#include <cstdio>
#include <algorithm>
#include <iostream>

const int N = 3e2;

int st[N + 5][N + 5];

int main() {

    int n; 
    scanf("%d", &n); 

    int m = n * n;
    for (int i = 1; i <= n; i ++) {
        if (i & 1) {
            for (int j = 1; j <= n; j ++) 
                st[j][i] = j + (i - 1) * n; 
        } else {
            for (int j = n, k = 1; j; j --, k ++) 
                st[j][i] = k + (i - 1) * n; 
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) printf("%d ", st[i][j]);
        printf("\n");
    }

    return 0; 
}