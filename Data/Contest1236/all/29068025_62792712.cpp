#include<bits/stdc++.h>
#define bi (1<<i)
#define bk (1<<k)
#define bj (1<<j)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const ll N=3e5+10,mod=1e9+7;
int as[400][400];
int main()
{
  //  freopen("i.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int c=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        if(i&1)
        as[i][j]=c++;
        else
        as[i][n-j+1]=c++;
    }
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            printf("%d ",as[j][i]);
            puts("");
        }
}
