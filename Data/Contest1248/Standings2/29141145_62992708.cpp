#include <bits/stdc++.h>
using namespace std;
#define ld long long double
#define ll long long
#define mod 1000000007
#define scl(x) scanf("%lld",&x)
ll mul(ll a,ll b){
    return ((a%mod)*(b%mod))%mod;
}

ll power(ll a,ll b) {
    ll res=1LL;
    while(b>0){
        if(b&1) res = mul(res,a);
        b/=2;
        a = mul(a,a);
    }
    return res%mod;
}

// ll tar[6][6];
// ll n,m;

// ll rec(ll a) {
//     if(a > (n*m)) {
//         for(ll i=0;i<n;i++) {
//             for(ll j=0;j<m;j++) {
//                 ll f=0;
//                 ll col = tar[i][j];
//                 if(i-1>=0 && tar[i-1][j] == col)f++;
//                 if(i+1<n && tar[i+1][j] == col)f++;
//                 if(j-1>=0 && tar[i][j-1] == col)f++;
//                 if(j+1<m &&tar[i][j+1] == col)f++;
//                 if(f > 1)return 0;        
//             }
//         }
//         return 1;
//     }
//     ll ans = 0;
//     tar[(a-1)/m][(a-1)%m]=1;
//     ans += rec(a+1);
//     tar[(a-1)/m][(a-1)%m]=0;
//     ans += rec(a+1);
//     return ans;
// }
ll Fib[5000005];
int main(){
    ll n,m;
    cin >> n >> m;
    // cout << rec(1) << endl;
    Fib[1]=2;
    Fib[2]=4;
    for(ll i=3;i<=n;i++) Fib[i] = (Fib[i-1] + Fib[i-2])%mod;
    Fib[1] = Fib[n];
    Fib[2] = Fib[1]+2;
    ll a = 0;
    ll b = 2;
    for(ll i=3;i<=m;i++) {
        Fib[i] = (Fib[i-1] + a + b)%mod;
        a = b;
        b = (Fib[i] - Fib[i-1] + mod)%mod;
    }
    cout << Fib[m] << endl;
}