#include<bits/stdc++.h>
using namespace std;
#define MAX 300001
#define MAX_POINTS 201
#define DEFAULT 1;
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
int main()
{
    int n;
    scanf("%d",&n);
    int groups[n][n];
    int i,j;
    int lab=1;
    for(j=0;j<n;j++)
    {
        if(j%2)
        {
            for(i=n-1;i>=0;i--)
            {
                groups[i][j]=lab++;
            }
        }
        else
        {
            for(i=0;i<n;i++)
            {
                groups[i][j]=lab++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",groups[i][j]);
        }
        printf("\n");
    }
    return 0;
}
