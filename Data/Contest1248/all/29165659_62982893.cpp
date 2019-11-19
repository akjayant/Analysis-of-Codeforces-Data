    #include <bits/stdc++.h>
     using namespace  std;
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    // What follows is a magical ordered_set data structure.
    // Supports the following functions:
    // find_by_order(ll k) - returns k'th smallest element (0-indexed)
    // order_of_key(ll k) - returns number of elements strictly smaller than k.
    using namespace __gnu_pbds;
    #define ordered_set tree <ll, null_type, less_equal <ll>, rb_tree_tag, tree_order_statistics_node_update> 
     
    #define mp make_pair
    #define pb push_back
    #define ff first
    // #define ll long long ll
    #define ss second
    #define uint128 __int128
    // #define ll long long
    const double pi=3.1415926535897932384626433832;
     long long mod= 1e9+7;
    //long long primeset[5000000]={};
    typedef complex<double> cd;
    typedef long long ll;
    typedef double ld;
    //#define For(i,0,n) for(long long i = 0 ; i<n ;i++) 
    //cd god (mod,0);
     
    cd fast_exp(cd a, long long b)
    {
      if (b == 0)
        return 1;
      
      cd res = fast_exp(a, b / 2);
        
      res = res *res;
      
      if (b % 2 == 1)
        {
          res = res * a;
         
     
        }    
      
      return res;
    }
     
    long long fastexpon(long long a,long long b,long long mod)
    {
      if(b==0)
        return 1LL;
      
      long long res=fastexpon(a,b/2,mod);
      
      res=(res*res)%mod;
      if(b%2==1)
        res= (res * a)%mod;
     
      return res;
    }
     
     
     
    //TEMPLATE ENDS HERE!!!! ------------------------------------------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------------------------------------------------------------------
    struct custom
    {
        bool operator()(ll a, ll b)
        {
         return a > b;
        }
    };
     
 
 
 
 
//bool nprime[6005]={}; 
     
int main() 
{
 
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
ll n;
cin>>n;
ll a[n];
for(ll i = 0; i<n ;i++)
{
  cin>>a[i];
}
sort(a,a+n,greater<ll>());
ll big = 0, small = 0;
for(ll i = 0 ; i<n ; i++)
{
  if(i<(n+1)/2)
    big+=a[i];
  else
    small+=a[i];
}

cout<<big*big+small*small<<endl;
 
return 0;
 
}