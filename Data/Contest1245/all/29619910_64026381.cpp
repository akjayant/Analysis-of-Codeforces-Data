#include<bits/stdc++.h>
using namespace std;
long long ans,n,x[2010],y[2010],c[2010],k[2010],tmp,node=1,u[2010];
bool check[2010];
vector<pair<long long,pair<long long,long long> > > edge;
vector<long long> fuck;
vector<pair<long long,long long> > fucking;
long long dist(long long i,long long j)
{
    if(i==0)
        return c[j];
    else if(j==0)
        return c[i];
    //cout<<i<<" "<<j<<""<<(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))<<"dist\n";
    return (k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
}
long long fd(long long a)
{
    if(u[a]<0)
        return a;
    return u[a] = fd(u[a]);
}
bool mg(long long a,long long b)
{
    a = fd(a);
    b = fd(b);
    if(a==b)
        return false;
    u[b]=a;
    return true;
}
int main()
{
    cin>>n;
    for(long long i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    for(long long i=1;i<=n;i++)
        cin>>c[i];
    for(long long i=1;i<=n;i++)
        cin>>k[i];
    for(long long i=0;i<=n;i++)
        u[i]=-1;
    edge.resize((n+1)*n/2);
    for(long long i=0;i<=n;i++)
        for(long long j=i+1;j<=n;j++)
            edge.push_back({dist(i,j),{i,j}});
    sort(edge.begin(),edge.end());
    long long cnt = 0, i = 0;
    while(1)
    {
        if(mg(edge[i].second.second,edge[i].second.first))
        {
            ans += edge[i].first;
            long long a1=edge[i].second.second;
            long long a2=edge[i].second.first;
            if(a1!=0&&a2!=0)
                fucking.push_back({a1,a2});
            else if(a1==0)
                fuck.push_back(a2);
            else
                fuck.push_back(a1);
            cnt++;
            if(cnt == n)
                break;
        }
        i++;
    }
    cout<<ans<<"\n";
    cout<<fuck.size()<<"\n";
    for(long long i=0;i<fuck.size();i++)
        cout<<fuck[i]<<" ";
    cout<<"\n";
    cout<<fucking.size()<<"\n";
    for(long long i=0;i<fucking.size();i++)
        cout<<fucking[i].first<<" "<<fucking[i].second<<"\n";
}
