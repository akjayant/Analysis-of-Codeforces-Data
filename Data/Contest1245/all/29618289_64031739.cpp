#include <bits/stdc++.h>
#define DIM 2007
#define INF 1000000007
using namespace std;

long long n,x[DIM],y[DIM],c[DIM],k[DIM],d[DIM];
long long dist[DIM],par[DIM];
int used[DIM];
int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>x[i]>>y[i];

    for(int i = 1; i <= n; ++i)
        cin>>c[i];

    for(int i = 1; i <= n; ++i)
        cin>>k[i];
    memset(par,-1,sizeof(par));
    long long res = 0;
    for(int i = 1; i <= n; ++i)
    {
        dist[i] = c[i];
        res += dist[i];
    }
    for(int i = 1; 1; ++i)
    {
        int mn = -1;
        for(int j = 1; j <= n; ++j)
            if((dist[mn]>dist[j]||mn==-1) && used[j]==0) mn = j;
        //cout<<mn<<endl;
        if(mn == -1) break;
        used[mn] = 1;
        for(int i = 1; i <= n; ++i)
            if(dist[i]>(abs(x[i]-x[mn])+abs(y[i]-y[mn]))*(k[i]+k[mn]) && i!=mn && used[i]==0)
        {
            res-=dist[i];
            dist[i] = (abs(x[i]-x[mn])+abs(y[i]-y[mn]))*(k[i]+k[mn]);
            res+=dist[i];
            par[i] = mn;
        }
    }
    int v1 = 0;
    for(int i = 1; i <= n; ++i)
        if(par[i]==-1) v1++;
    cout<<res<<endl<<v1<<endl;
    for(int i = 1; i <= n; ++i)
        if(par[i]==-1) cout<<i<<' ';
        cout<<endl<<n-v1<<endl;
        for(int i = 1; i <= n; ++i)
            if(par[i]!=-1)cout<<i<<' '<<par[i]<<endl;
    return 0;
}
