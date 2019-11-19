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
       ll n;cin>>n;
       //ll arr[n];
       ll cnt1 = 0;
       for(ll i=0;i<n;i++)
       {
           ll temp;
           cin>>temp;
           if(temp%2 == 0)
                cnt1++;
       }
       
       ll m;cin>>m;
       //ll arr[n];
       ll cnt2 = 0;
       for(ll i=0;i<m;i++)
       {
           ll temp;
           cin>>temp;
           if(temp%2 == 0)
                cnt2++;
       }
       
       cout<<(cnt1*cnt2) + (n-cnt1)*(m-cnt2)<<"\n";
   }
   
   
   return 0;
}