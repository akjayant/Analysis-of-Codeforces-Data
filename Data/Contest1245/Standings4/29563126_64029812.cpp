#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<" --> "<<x<<endl;
#define N 100005
#define M 1000000007
#define pii pair<ll,ll>
using namespace std;
map<pii,bool>mp;
ll par[N];
ll c[N],x[N],y[N],k[N];
ll fin(ll a)
{
    if(par[a]==a)
        return a;
    return par[a]=fin(par[a]);
}
void un(ll a,ll b)
{
    a=fin(a);
    b=fin(b);
    if(a==b)
        return ;
    else
    {
        if(c[a]<c[b])
        {
            par[b]=a;
        }
        else
            par[a]=b;
    }
}
vector<ll>e[N];
main()
{
    for(ll i=0; i<N; i++)
        par[i]=i;
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>x[i]>>y[i];
    }
    for(ll i=0; i<n; i++)
    {
        cin>>c[i];
    }
    vector<pair<ll,pii>>v;
    for(ll i=0; i<n; i++)
    {
        cin>>k[i];
    }
    for(ll i=0; i<n; i++)
    {
        for(ll j=i+1; j<n; j++)
        {
            ll need=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
            v.push_back({need,{i,j}});

        }
    }
    sort(v.begin(),v.end());


    for(auto tr:v)
    {
        ll i=tr.second.first;
        ll j=tr.second.second;
        if(i!=j)
        {
            ll a=fin(i);
            ll b=fin(j);
            ll c1=c[a];
            ll c2=c[b];
            ll need=abs(x[i]-x[j])+abs(y[j]-y[i]);
            need*=(k[i]+k[j]);
            if(need<max(c1,c2)&&a!=b)
            {
                    ll t1=i;
                    ll t2=j;
                    //mn=min(need,mn);
                    un(t1,t2);
                    e[t1+1].push_back(t2+1);

            }
        }
    }


ll ans=0;
map<ll,bool>uu;
vector<ll>a1;
for(ll i=0; i<n; i++)
{
    ll j=fin(i);
    if(!uu[j])
    {
        ans+=c[j];
        a1.push_back(j+1);
        uu[j]=true;

    }
}
ll ed=0;
for(ll i=1; i<=n; i++)
{
    for(auto u:e[i])
    {
        ed++;
        ans+=(abs(x[i-1]-x[u-1])+abs(y[i-1]-y[u-1]))*(k[i-1]+k[u-1]);

    }
}
cout<<ans<<'\n';
cout<<a1.size()<<'\n';
for(auto u:a1)
{
    cout<<u<<' ';
}
cout<<'\n';
cout<<ed<<'\n';
for(ll i=1; i<=n; i++)
{
    for(auto u:e[i])
    {
        cout<<i<<' '<<u<<'\n';
    }
}


}
