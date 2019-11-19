#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
const int sz = 4002005;
const int N = 2005;
long long n,p[sz],rk[sz],dem,d1,d2,res,w[N],k[N],x[N],y[N];
long long cnt=0;
pair<long long,pair<long long,long long>> a[sz];
vector <pair<long long,long long> > ans;
pair<long long,long long> ans1[sz];
long long luu[sz];
long long FI(long long u)
{
    long long v=p[u];
    while(v!=u)
    {
        u=v;
        v=p[u];
    }
    return u;
}
void Un(long long u,long long v)
{
    long long x=FI(u);
    long long y=FI(v);
    if(x==y)
        return;
    else
    {
        if(rk[x]>rk[y])
            p[y]=x;
        if(rk[x]<rk[y])
            p[x]=y;
        if(rk[x]==rk[y])
        {
            p[y]=x;
            rk[x]++;
            return ;
        }
    }
}
main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin>>n;
    FOR(i,1,n)
        cin>>x[i]>>y[i];
    FOR(i,1,n)
        cin>>w[i];
    FOR(i,1,n)
        cin>>k[i];
    FOR(i,1,n)
        FOR(j,i+1,n){
                a[++cnt].first=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
                a[cnt].second.first=i;
                a[cnt].second.second=j;
        }
    for(long long i=1; i<=n; i++)
    {
        a[++cnt].first=w[i];
        a[cnt].second.first=n+1;
        a[cnt].second.second=i;
    }
    sort(a+1,a+1+cnt);
    FOR(i,1,n)
        p[i]=i;
    FOR(i,1,n*n+n)
        if(FI(a[i].second.first)!=FI(a[i].second.second))
        {
            Un(a[i].second.first,a[i].second.second);
            ans.push_back({a[i].second.first,a[i].second.second});
            res+=a[i].first;
        }
    cout<<res<<endl;
    FOR(i,0,ans.size()-1)
    {
        if(ans[i].first==n+1)
           luu[++d1] = ans[i].second;
        else ans1[++d2] = {ans[i].first,ans[i].second};
    }
    cout<<d1<<endl;
    sort(luu+1,luu+1+d1);
    FOR(i,1,d1)
        cout<<luu[i]<<" ";
    cout<<endl;
    cout<<d2<<endl;
    FOR(i,1,d2)
        cout<<ans1[i].first<<" "<<ans1[i].second<<endl;
}
