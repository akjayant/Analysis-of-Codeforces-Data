#include <bits/stdc++.h>
#define maxn 300
#define LL long long int
using namespace std;

int maze[maxn+5][maxn+5];
int main()
{
    int n;cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        for(int j=0;j<n;j++)
        {
            maze[j][i]=++cnt;
        }
        else
        for(int j=n-1;j>=0;j--)
        {
            maze[j][i]=++cnt;
        }
    }

    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        printf("%d",maze[i][j]);
        if(j!=n-1)printf(" ");
        else printf("\n");
    }
    return 0;
}
