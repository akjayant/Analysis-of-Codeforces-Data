#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

#define N 308

int n, cnt = 0;
int a[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = ++cnt;
    for (int i = 1; i <= n/2; i++)
        for (int j = 1; j <= n/2; j++)
            swap(a[i][j], a[i][n-j+1]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            printf("%d%c", a[j][i], j == n ? '\n' : ' ');
    return 0;
}