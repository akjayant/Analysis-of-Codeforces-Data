#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=4e5+10;
const int MOD=1e9+7;

int a[305][305];

int main()
{
    int n;
    scanf("%d",&n);
    int inv=1;
    for(int i=1;i<=n;i++)
    {
        if(inv)
        for(int j=1;j<=n;j++)
            a[j][i]=(i-1)*n+j;
        else
        for(int j=1;j<=n;j++)
            a[j][i]=(i-1)*n+(n-j+1);
        inv^=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
