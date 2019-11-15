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
ll v[N],s[N];
int main()
{
    //freopen("i.txt","r",stdin);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int as=0;
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=100;j++)
            {
                if(i<=a&&2*i+j<=b&&2*j<=c)
                    as=max(as,3*i+3*j);
            }
        }
        printf("%d\n",as);
    }
}
