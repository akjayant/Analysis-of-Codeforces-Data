#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int N = 2e3+10;
const int M = 4e6+10;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int n;
ll x[N],y[N],c[N],k[N];
ll dis[N][N],prim[N],g[N];
ll cost;
int tots,s[N],v[N];
int tote,ex[N],ey[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",x+i,y+i);
        v[i]=0;
    }
    int S;
    ll mi=1e9+7;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",c+i);
        if(c[i]<mi)
        {
            mi=c[i];
            S=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",k+i);
        dis[i][i]=1ll<<62;
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            dis[i][j]=dis[j][i]=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
        }
    for(int i=1;i<=n;i++)
    {
        if(dis[S][i]<c[i])
        {
            prim[i]=dis[S][i];
            g[i]=S;
        }
        else
        {
            prim[i]=c[i];
            g[i]=0;
        }
    }
    s[++tots]=S;
    v[S]=1;
    cost+=mi;
    for(int cas=1;cas<n;cas++)
    {
        ll Mi=(1ll << 62);
        int nxt;
        for(int i=1;i<=n;i++)
        {
            if(!v[i]&&prim[i]<Mi)
            {
                Mi=prim[i];
                nxt=i;
            }
        }
        v[nxt]=1;
        cost+=prim[nxt];
        if(g[nxt]==0)
        {
            s[++tots]=nxt;
        }
        else
        {
            ex[++tote]=g[nxt];
            ey[tote]=nxt;
        }
        for(int i=1;i<=n;i++)
        {
            if(prim[i]>dis[nxt][i])
            {
                prim[i]=dis[nxt][i];
                g[i]=nxt;
            }
        }
    }
    cout<<cost<<endl;
    cout<<tots<<endl;
    for(int i=1;i<=tots;i++)
    {
        if(i!=1)cout<<" ";
        cout<<s[i];
    }cout<<endl;
    cout<<tote<<endl;
    for(int i=1;i<=tote;i++)
        cout<<ex[i]<<" "<<ey[i]<<endl;
    return 0;
}
