#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll N = 750002;
const int mod = 1000000007;
const long long int inf = INT64_MAX;
#define pp pair<ll,ll>

typedef long double ld;
typedef vector<pp> vpl;
#define MP make_pair
#define endl "\n"
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<n;i++)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define repb(i,n) for(ll i=1;i<n-1;i++) 
#define trace(i,a) for(auto i=a.begin();i!=a.end();i++)    
void fastIO(void);
 
void decimal(int);
ll modmulti(ll, ll);
ll modadd(ll, ll);
ll modpower(ll, ll);
ll gcd(ll, ll );
ll modinv(ll);

int main()
{  
   
   ll n,m;
   cin>>n>>m;
   ll ans = (modpower(2,m)-1+mod)%mod;
   ans = modpower(ans,n);
   cout<<ans<<endl;

}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
void fastIO(void)
{  ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
}
 
void decimal(int n){
   cout<<fixed;
   cout<<setprecision(n);
}
ll modmulti(ll a, ll b){
   return ((a%mod)*(b%mod))%mod;
}
ll modadd(ll a, ll b){
   return ((a%mod)+(b%mod)+mod)%mod;
}
ll modpower(ll a, ll n){
   if(n==0)
      return 1;
   ll result = 1;
   while(n>0){
      if(n%2==1)
         result = modmulti(result,a);
      a = modmulti(a,a);
      n = n/2;
   }
   return result;
}
ll gcd(ll a, ll b){
   if(b==0)
      return a;
   return gcd(b,a%b);
}
ll modinv(ll a){
   return modpower(a,mod-2);
}
 