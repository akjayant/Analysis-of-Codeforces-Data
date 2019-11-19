#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define MOD 1000000007 

using namespace std;

int main()
{
   FAST/**/
   
   ll n;
   cin>>n;
   
   pair<ll,ll> arr[n];
   for(ll i=0;i<n;i++)
        cin>>arr[i].first>>arr[i].second;
   
   ll crr[n],krr[n];
   for(ll i=0;i<n;i++)
        cin>>crr[i];
   for(ll i=0;i<n;i++)
        cin>>krr[i];
   
   ll cost[n][n];
   ll para[n];
   for(ll i=0;i<n;i++)
        para[i] = i;
   for(ll i=0;i<n;i++)
   {
       for(ll j=0;j<n;j++)
       {
           if(i == j)
                continue;
           cost[i][j] = (abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second))*(krr[i] + krr[j]);        
       }
   }
   
   set<pair<ll,ll>> st;
   for(ll i=0;i<n;i++)
        st.insert(mp(crr[i],i));
   
   ll costi[n];
   for(ll i=0;i<n;i++)
        costi[i] = crr[i];
   
   bool vis[n];
   memset(vis,0,sizeof(vis));
   
   while(st.size()>0)
   {
       pair<ll,ll> curr = *st.begin();
       st.erase(st.begin());
       vis[curr.second] = 1;
       for(ll i=0;i<n;i++)
       {
           if(vis[i])
                continue;
           if(cost[i][curr.second]<costi[i])
           {
               para[i] = curr.second;
               st.erase(mp(costi[i],i));
               costi[i] = cost[i][curr.second];
               st.insert(mp(costi[i],i));
           }
       }
       
   }
   
   ll ans = 0;
   for(ll i=0;i<n;i++)
        ans+=costi[i];  
        
   ll cnt = 0;
   for(ll i=0;i<n;i++)
   {
       if(para[i] == i)
            cnt++;
   }
   
   cout<<ans<<"\n"<<cnt<<"\n";  
   for(ll i=0;i<n;i++)
   {
       if(para[i] == i)
            cout<<i+1<<" ";
   }
   
   cout<<"\n";
   ll temp = 0;
   for(ll i=0;i<n;i++)
   {
       if(para[i]!=i)
            temp++;
   }
   
   cout<<temp<<"\n";
   for(ll i=0;i<n;i++)
   {
       if(para[i]!=i)
            cout<<para[i]+1<<" "<<i+1<<"\n";
   }
   
   
   
   
   return 0;
}