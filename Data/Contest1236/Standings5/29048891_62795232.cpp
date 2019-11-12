#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define int long long
#define pb push_back
const int mod = 1e9 + 7;

ll power(ll a , ll n){
        ll res = 1;
        if(n==0){
            return res;
        }
        while(n/2){
            if(n%2 == 1){
                res = (res%mod*a%mod)%mod;
            }
            a = (a%mod*a%mod)%mod;
            n/=2;
        }
        res = (res*a)%mod;
 	return res;
}

signed main(){
    int n, m;
    
    cin >> n >> m;
    
    int ans = (power(2,m) - 1LL + mod)%mod;
    ans = power(ans,n);
    ans%=mod;
    
    cout << ans << '\n'; 
}