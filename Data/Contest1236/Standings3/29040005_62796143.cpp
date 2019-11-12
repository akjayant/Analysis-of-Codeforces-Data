#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[350][350];
int n;

int main()
{
    scanf("%d",&n);
    int flag=1;
    for(int i=1;i<=n;++i)
    {
        if(flag==true)
        {
            for(int j=1;j<=n;++j)
            {
                a[j][i]=(i-1)*n+j;
            }
        }
        else
        {
            for(int j=1;j<=n;++j)
            {
                a[j][i]=(i-1)*n+(n-j+1);
            }
        }
        flag=1-flag;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            printf("%d ",a[i][j]);
        }
        puts("");
    }
    return 0;
}
