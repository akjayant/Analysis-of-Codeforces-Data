#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1000000007;

int power(int x, int y, int p) 
{ 
    int res = 1;      // Initialize result 
  
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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    int ans = 1;
    ans = power(2, m, mod);
    ans -= 1;
    if(ans < 0)ans+=mod;
    ans %= mod;
    ans = power(ans, n, mod);
    cout<<ans;
    return 0;
}