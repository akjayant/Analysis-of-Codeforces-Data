#include<bits/stdc++.h>
using namespace std;
int p2i(int x, int y)
{
    if(x%2 == 0) return x*10+y;
    return x*10+9-y;
}
int arr[10][10];
int flatten[100];
double dp[100];
int main()
{
    for(int i=0; i<10; ++i)
        for(int j=0; j<10; ++j)
        {
            scanf("%d", &arr[i][j]);
            int c = p2i(i, j);
            flatten[c] = -1;
            if(arr[i][j])
            {
                int ni = i-arr[i][j];
                int nj = j;
                flatten[c] = p2i(ni, nj);
            }
        }
    dp[0] = 0;
    for(int i=1; i<100; ++i)
    {
        double ans = 0;
        int pass = 0;
        for(int j=1; j<=6; ++j)
        {
            if(j>i)
            {
                ++pass; continue;
            }
            int dest = i-j;
            double cost = dp[dest];
            
            if(flatten[dest] != -1)
                cost = min(cost, dp[flatten[dest]]);
            ans += cost;
        }
        dp[i] = (ans+6)/(6-pass);
    }
    printf("%.12f\n", dp[99]);
}