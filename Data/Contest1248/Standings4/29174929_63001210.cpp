    #include<bits/stdc++.h>
    
    using namespace std;
    #define ll long long int
    #define mod 1000000007
    int main()
    {
       ll n , m;
       cin >> n >> m;
       ll mx = max( n, m);
       ll dp[mx + 1];
       dp[1] = 1;
       if(mx > 1)
       {
           dp[2] = 2;
           for(ll i = 3 ; i <= mx; i++)
           {
               dp[i] = (dp[i - 1] % mod + dp[i-2] % mod) % mod;
           }
       }
       ll ans = (dp[n] % mod + dp[m] % mod - 1 )%mod;
       ans = (ans * 2) % mod;
       cout << ans <<endl;
      
    }