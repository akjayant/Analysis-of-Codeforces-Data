#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
const int maxn=310;
int a[maxn][maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int j=1;j<=n;j++)
        if(j%2)
            for(int i=1;i<=n;i++)
                a[i][j]=i+(j-1)*n;
        else
            for(int i=1;i<=n;i++)
                a[i][j]=n+1-i+(j-1)*n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
