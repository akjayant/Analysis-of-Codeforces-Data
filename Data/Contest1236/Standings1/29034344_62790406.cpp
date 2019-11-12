#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll c = 1e9+7;

/* Iterative Function to calculate (x^y)%p in O(log y) */
ll power2(ll x, ll y, ll p) 
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

// ll power1(ll a,ll p, ll c){
//     ll res = 1;
//     while(p>0){
//         if(p&1){
//             res = (res*a)%c;
//         }
//         p=(p>>1);
//         a = (a*a)%;
//     }
//     return res;
// }

int main(int argc, char const *argv[])
{
    ll n,m;
    cin>>n>>m;
    ll t = power2(2,m,c) - 1;
    t = power2(t,n,c);
    cout<<t<<"\n";   
    return 0;
}