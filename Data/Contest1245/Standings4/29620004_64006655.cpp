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
       ll a,b;
       cin>>a>>b;
       
       if(a>b)
            swap(a,b);
       if(__gcd(a,b)!=1)
            cout<<"Infinite\n";
       else cout<<"Finite\n";        
   }
   
   return 0;
}