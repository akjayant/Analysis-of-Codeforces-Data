#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
   FAST/**/
   
   ll t;
   cin>>t;
   
   while(t--)
   {
       ll n;
       cin>>n;
       
       ll arr[n];
       for(ll i=0;i<n;i++)
            cin>>arr[i];
       
       sort(arr,arr+n);
       ll maxi = 1;
       for(ll i=0;i<n;i++)
       {
           maxi = max(maxi, min(arr[i],n-1-i+1));
       }
       
       cout<<maxi<<"\n";
   }
   
   return 0;
}