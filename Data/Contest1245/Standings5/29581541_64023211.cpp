#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define N 100050
using namespace std;
ll mod= 1e9+7;
ll c[N],k[N];
ll vis[N];
ll x[N],y[N];
ll n;
vector< pair< ll, ll > > edges;
vector< ll > ver;
set< pair<ll, pair< ll, ll > > > s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   cin>>n;
   for(int i=0;i<n;i++)
    cin>>x[i]>>y[i];
   for(ll i=0;i<n;i++)
    cin>>c[i];
   for(ll i=0;i<n;i++)
    cin>>k[i];

   for(ll i=0;i<n;i++){
    s.insert({c[i],{i,-1LL}});
   }
   ll ans=0;
   while(!s.empty()){
   set< pair<ll, pair< ll, ll > > >  :: iterator it= s.begin();
    ll cos=it->first;
    ll node=it->second.first;
    ll via=it->second.second;
    s.erase(s.begin());
    if(cos>c[node]){
        continue;
    }
    vis[node]=1;
    ans+=cos;
    if(via==-1){
        ver.push_back(node);
    }
    else {
        edges.push_back({node,via});
    }
    for(ll i=0;i<n;i++){
    if(vis[i]==1)continue;
    ll len=abs(x[i]-x[node])+abs(y[i]-y[node]);
     if(c[i]>((k[node]+k[i])*len)){
        c[i]=len*(k[node]+k[i]);
        s.insert({c[i],{i,node}});
     }
    }
   }
   cout<<ans<<"\n";
   cout<<ver.size()<<"\n";
   for(auto a: ver)
    cout<<a+1<<" ";
    cout<<"\n";
   cout<<edges.size()<<"\n";
   for(auto h: edges)
    cout<<h.first+1<<" "<<h.second+1<<"\n";
   return 0;
}
