#include<bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
const int mod=1e9+7;
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define si(a) a.size()
#define pii pair<int,int>
using namespace std;
#if !defined(ONLINE_JUDGE)
#include "debugging.h"
#endif

const int N=2005;
pii city[N];
int vis[N],c[N],k[N],dp[N],ans[N];
vector<pii> g[N];
set<pii>st;

int wire(int i,int j)
{
   int dist=abs(city[i].F - city[j].F) + abs( city[i].S - city[j].S );
   dist*= (k[i]+k[j]);
   return dist;
}

int32_t main() {
   std::ios::sync_with_stdio(false);cin.tie(NULL);
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      cin>>city[i].F>>city[i].S;
   }
   for(int i=1;i<=n;i++)cin>>c[i];
   for(int i=1;i<=n;i++)cin>>k[i];
   
   for(int i=1;i<=n;i++)
   {
      st.insert({c[i],i});
      dp[i]=c[i];
   }
   int x=0;
   while(!st.empty())
   {
      pii p=*st.begin();
      st.erase(p);
      int node=p.S,d=p.F;
      vis[node]=1;
      x+=dp[node];
      //dbgm(node,dp[node]);
      for(int j=1;j<=n;j++)
      {
         if(vis[j])continue;
         if( dp[j] > wire(node,j))
         {
            st.erase( {dp[j],j} );
            dp[j]=wire(node,j);
            st.insert( {dp[j],j} );
            ans[j]=node;
         }
      }
   }
   vector<int>grid;
   for(int i=1;i<=n;i++)
   {
      if(dp[i]==c[i])
      grid.pb(i);
   }
   cout<<x<<endl;
   cout<<grid.size()<<endl;
   for(int i:grid)cout<<i<<' ';cout<<endl;
   x=0;
   vector<pii>conn;
   for(int i=1;i<=n;i++)
   {
      if(ans[i])conn.pb({ans[i],i});
      //dbgm(i,ans[i]);
   }
   cout<<conn.size()<<endl;
   for(pii p:conn)
   cout<<p.F<<' '<<p.S<<endl;
   return 0;
}