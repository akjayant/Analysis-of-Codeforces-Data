#include <bits/stdc++.h>
using namespace std;

const int maxn = 305;
int G[maxn][maxn];
int n;

int main()
{
    scanf("%d",&n);
    int cnt = 1;
    for(int i = 1;i <= n; ++i)
    {
        if(i % 2 == 1)
        for(int j = 1;j <= n; ++j)
            G[j][i] = cnt++;
        else
        for(int j = n;j >= 1; --j)
            G[j][i] = cnt++;
    }
    for(int i = 1;i <= n; ++i)
    {
        for(int j = 1;j <= n; ++j)
        {
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
    return 0;
}