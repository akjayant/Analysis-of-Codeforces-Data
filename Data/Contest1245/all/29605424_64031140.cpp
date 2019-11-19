#include <bits/stdc++.h>
using namespace std;

int n;
int a[2005];
int b[2005];
int lt[2005];
typedef pair < int,int > II;
typedef pair < int64_t, II > III;
III tmp[4100005];
int sl=0;
int64_t ans=0;
int c[2005];
int d[2005];
int res,res1;
int sn[2005];
II sn1[4004];
#define fr first
#define sc second

int tim(int u)
{
    if(lt[u]==u)
        return u;

    lt[u]=tim(lt[u]);

    return lt[u];
}

int main ()
{
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);

    scanf("%d ",&n);

    for(int i=1; i<=n; ++i)
        scanf("%d %d ",&a[i],&b[i]);

    for(int i=1; i<=n; ++i)
        lt[i]=i;

    for(int i=1; i<=n; ++i)
        scanf("%d ",&c[i]);

    for(int i=1; i<=n; ++i)
        scanf("%d ",&d[i]);

    for(int i=1; i<=n; ++i)
        tmp[++sl]= {c[i],{0,i}};

    for(int i=1; i<=n; ++i)
        for(int j=i+1; j<=n; ++j)
        {
            int hi=d[i]+d[j];
            int lo=abs(a[i]-a[j])+abs(b[i]-b[j]);

            tmp[++sl]= {1ll*hi*lo,{i,j}};
        }

    sort(tmp+1,tmp+sl+1);

    for(int i=1; i<=sl; ++i)
    {
        int u=tmp[i].sc.fr;
        int v=tmp[i].sc.sc;

        u=tim(u);
        v=tim(v);

        if(u!=v)
        {
            ans+=tmp[i].fr;
            lt[u]=v;
            if(tmp[i].sc.fr==0)
                sn[++res]=tmp[i].sc.sc;
            else
                sn1[++res1]=tmp[i].sc;
        }
    }

    printf("%I64d \n",ans);

    printf("%d \n",res);

    sort(sn+1,sn+res+1);

    for(int i=1; i<=res; ++i)
        printf("%d ",sn[i]);

    printf("\n");

    printf("%d \n",res1);

    for(int i=1; i<=res1; ++i)
        printf("%d %d \n",sn1[i].fr,sn1[i].sc);
}
