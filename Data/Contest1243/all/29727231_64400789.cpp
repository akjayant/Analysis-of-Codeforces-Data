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
   
   if(n == 1)
   {
       cout<<1;
       return 0;
   }
   
   if(n == 2)
   {
       cout<<2;
       return 0;
   }
   
   ll g = 0;
   
   for(ll i=2;i<=sqrt(n);i++)
   {
       if(n%i == 0)
       {
           g = __gcd(i,g);
           g = __gcd(n/i,g);
       }
   }
   
   if(g == 0)
   {
       cout<<n;
       return 0;
   }
   
   cout<<g;
   
   return 0;
}