#include "bits/stdc++.h"
using namespace std;
#define int int64_t
#define mp make_pair
#define f first
#define s second
int tc[1<<17];
int cost[1<<17];
pair<int,int> ar[1<<17];
int costing[1<<17];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i].f>>ar[i].s;
    }
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>tc[i];
    }
    priority_queue<pair<int, pair<int,int> > > pq;
    for(int i=0;i<n;i++)
    {
        pq.push(mp(-1*cost[i],mp(i,-1)));
        costing[i]=cost[i];
    }
    set<int> visited;
    set<int> power;
    int ans=0;
    set<pair<int,int> > paths;
    while(!pq.empty())
    {
        auto j=pq.top();
        pq.pop();
        if(visited.find(j.s.f)!=visited.end())
            continue;
        ans-=j.f;
        visited.insert(j.s.f);
        if(j.s.s==-1)
        {
            power.insert(j.s.f);
        }
        else
        {
            paths.insert(mp(j.s.f,j.s.s));
        }
        for(int i=0;i<n;i++)
        {
            if(i!=j.s.f and visited.find(i)==visited.end())
            {
                int kk=abs(ar[i].f-ar[j.s.f].f)+abs(ar[i].s-ar[j.s.f].s);
                kk*=(tc[i]+tc[j.s.f]);
                if(kk<costing[i])
                {
                    costing[i]=kk;
                    pq.push(mp(-1*kk,mp(i,j.s.f)));
                }
            }
        }
    }
    cout<<ans<<"\n";
    cout<<power.size()<<"\n";
    for(int i:power)
        cout<<i+1<<" ";
    cout<<"\n";
    cout<<paths.size()<<"\n";
    for(auto i:paths)
        cout<<i.f+1<<" "<<i.s+1<<"\n";
    return 0;
}
