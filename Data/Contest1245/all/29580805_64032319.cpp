#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<ll,ll> >vec,ans;
vector<pair<ll,pair<ll,ll> > >vec2;
vector<ll>vec3;
ll cost[2009];
ll kk[2009];
ll par[2009];
ll find_par(ll a)
{
    if(par[a]==a)return a;
    return par[a]=find_par(par[a]);
}
int main()
{
    ll a,b,c,d,e,i,j,k,l,n,m,x,y,t,p,u,v;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&a,&b);
        vec.push_back({a,b});
    }
    for(i=0;i<=n;i++)
    {
        par[i]=i;
    }
    x=0;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&cost[i]);
        x+=cost[i];
    }
    for(i=0;i<n;i++)
    {
        scanf("%lld",&kk[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            a=abs(vec[i].first-vec[j].first);
            b=abs(vec[i].second-vec[j].second);
            a=a+b;
            a=a*(kk[i]+kk[j]);
            vec2.push_back(make_pair(a,make_pair(i,j)));
        }
    }
    sort(vec2.begin(),vec2.end());
    l=vec2.size();
    for(i=0;i<l;i++)
    {
        a=vec2[i].second.first;
        b=vec2[i].second.second;
        u=find_par(a);
        v=find_par(b);
        if(u!=v)
        {
            c=max(cost[u],cost[v]);
            d=vec2[i].first;
            if(c>d)
            {
                if(cost[u]>=cost[v])
                {
                    par[u]=v;
                    x-=cost[u];
                    x+=d;
                    ans.push_back({a,b});
                }
                else
                {
                    par[v]=u;
                    x-=cost[v];
                    x+=d;
                    ans.push_back({a,b});
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        a=find_par(i);
        if(a==i)
        {
            vec3.push_back(i+1);
        }
    }
    printf("%lld\n",x);
    l=vec3.size();
    printf("%lld\n",l);
    for(i=0;i<l;i++)
    {
        printf("%lld ",vec3[i]);
    }
    printf("\n");
    l=ans.size();
    printf("%lld\n",l);
    for(i=0;i<l;i++)
    {
        printf("%lld %lld\n",ans[i].first+1,ans[i].second+1);
    }
    printf("\n");
}
