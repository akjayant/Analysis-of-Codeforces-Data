#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef int ll;
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
   
   vector<ll> v[n+1];
  // ll ans[n+1];
   //memset(ans,0,sizeof(ans));
   for(ll i=1;i<=n;i++)
   {
       if(i%2 == 1)
       {
           for(ll j=1 + (i-1)*n;j<=i*n;j++)
               v[j - (i-1)*n].pb(j);
       }
       
       else
       {
           for(ll j=i*n;j>=1 + (i-1)*n;j--)
               v[(i)*n+1-j].pb(j);
       }
   }
   
   /*ll ans = n*n;
   
   for(ll i=1;i<=n;i++)
   {
       for(ll j=1;j<=n;j++)
       {
           if(i == j)
                continue;
           ll arr[2*n];
           for(ll i1=0;i1<n;i1++)
                arr[i1] = v[i][i1];
           for(ll i1=0;i1<n;i1++)
                arr[i1+n] = v[j][i1];
           ans = min(ans, mergeSort(arr, 2*n))        
       }
   }*/
   
   for(ll i=1;i<=n;i++)
   {
       for(ll j=0;j<n;j++)
            cout<<v[i][j]<<" ";
       cout<<"\n";        
   }
   
   
   
   return 0;
}