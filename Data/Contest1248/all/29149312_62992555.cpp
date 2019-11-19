/*
 _     _    ___  ___  __ __ 
| |   | |  |__ \|__ \/_ /_ |
| |__ | |__   ) |  ) || || |
| '_ \| '_ \ / /  / / | || |
| |_) | |_) / /_ / /_ | || |
|_.__/|_.__/____|____||_||_|

*/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

#define N  100005
ll expo(ll base,ll exponent,ll mod){
    ll ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(ans*base)%mod;
        base=(base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
ll modInverse(ll n, ll p) 
{ 
    return expo(n, p-2, p); 
} 
  
ll fac[N+1]; 
// Returns nCr % p using Fermat's little 
// theorem. 
ll nCrModPFermat(ll n, ll r, ll p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    
    
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        fac[0] = 1; 
    for (int i=1 ; i<=N; i++) 
        fac[i] = fac[i-1]*i%hell; 
  
        ll n,m;
        cin>>n>>m;
        ll dn=n,c2=0;
        ll ans=0;
        rep(i,0,n/2+1)
        {
            dn=n-i;
            // cout<<nCrModPFermat(dn,i,hell)<<endl;
            ans+=((2*nCrModPFermat(dn,i,hell))%hell);
            ans%=hell;
        }
        // cout<<ans<<endl;
        rep(i,1,m/2+1)
        {
            dn=m-i;
            ans+=((2*nCrModPFermat(dn,i,hell))%hell);
            ans%=hell;
        }
        cout<<ans<<endl;
    }
    return 0;
}