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

       ll n;
       cin>>n;
       
       ll arr[n];
       for(ll i=0;i<n;i++)
            cin>>arr[i];
       sort(arr,arr+n);
       
       ll c1=0, c2=0;
       for(ll i=0;i<n/2;i++)
            c1+=arr[i];
       
       for(ll i=n/2;i<n;i++)
            c2+=arr[i];
       
       ll ans = c1*c1 + c2*c2;
       
       cout<<ans<<"\n";
   return 0;
}