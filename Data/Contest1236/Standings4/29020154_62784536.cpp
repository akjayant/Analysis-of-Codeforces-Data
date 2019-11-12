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
       ll a,b,c;
       cin>>a>>b>>c;
       
       ll ans = 0;
       for(ll i=0;i<=min(a,b/2);i++)
       {
           for(ll j=0;j<=min(b-2*i,c/2);j++)
           {
               ans = max(ans, i + 2*i + j + 2*j);
           }
       }
       
       cout<<ans<<"\n";
   }
   
   
   
   return 0;
}