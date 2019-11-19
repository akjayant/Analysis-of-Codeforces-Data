#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll *id,*val;
ll *c,*k;
void init()
{
    id=new ll[n];
    val=new ll[n];
    for(int i=0;i<n;i++)
    {
        id[i]=i;
        val[i]=c[i];
    }
}
  ll root(ll i)
{
    ll j=i;
    while(id[j]!=j)
        j=id[id[j]];
    while(i!=j)
    {
        ll newp=id[i];
        id[i]=j;
        i=newp;
    }
        return j;
}
   bool connected(ll p,ll q)
    {
        return root(p)==root(q);
    }
void unions(ll p,ll q)
    {
        ll i=root(p);
         ll j=root(q);
     if(val[i] > val[j]){
         id[i]=j;
         val[i]=0;
     }
     else{
        id[j]=i;
        val[j]=0;
     }
    }

struct edge
{
    ll u,v,w;
};
bool cmp(edge a,edge b)
{
    return a.w <= b.w;
}
vector<edge> ed;
int main() {
    cin>>n;
    vector<pair<ll,ll> > cd(n);
    for(int i=0;i<n;i++)
        cin>>cd[i].first>>cd[i].second;
        c=new ll[n];
    for(int i=0;i<n;i++)
        cin>>c[i];
        k=new ll[n];
    for(int i=0;i<n;i++)
        cin>>k[i];
        init();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            edge e;
            e.u=i+1;
            e.v=j+1;
            e.w=(k[i]+k[j])*(abs(cd[i].first-cd[j].first) + abs(cd[i].second-cd[j].second));
            ed.push_back(e);
        }
    }
    sort(ed.begin(),ed.end(),cmp);
    ll ans=0;
    for(int i=0;i<n;i++)
        ans+=c[i];
    vector<ll> aa;
    vector<pair<ll,ll> > edd;
    for(int i=0;i<ed.size();i++)
    {
        ll u1=ed[i].u-1;
        ll v1=ed[i].v-1;
        ll wt=ed[i].w;
        if(!connected(u1,v1))
        {
            if(ans > ans + wt - max(val[root(u1)],val[root(v1)]))
            {
                ans= ans + wt - max(val[root(u1)],val[root(v1)]);
                unions(u1,v1);
                edd.push_back(make_pair(u1+1,v1+1));
            }
        }
    }
    for(int i=0;i<n;i++)
        if(val[i]!=0)
        aa.push_back(i+1);
    cout<<ans<<"\n";
    cout<<aa.size()<<"\n";
    for(int i=0;i<aa.size();i++)
        cout<<aa[i]<<" ";
    cout<<"\n";
    cout<<edd.size()<<"\n";
    for(int i=0;i<edd.size();i++)
        cout<<edd[i].first<<" "<<edd[i].second<<"\n";
}
