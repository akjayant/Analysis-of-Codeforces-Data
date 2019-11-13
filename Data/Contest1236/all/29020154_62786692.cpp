#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define MOD 1000000007

using namespace std;

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 

int main()
{
   FAST/**/
   
   ll n,m;
   cin>>n>>m;
   
   ll ans = power(2,m,MOD);
   ans-=1;
   ans%=MOD;
   if(ans<0)
        ans+=MOD;
   
   ans = power(ans,n,MOD);
   cout<<ans;
   
   
   
   return 0;
}