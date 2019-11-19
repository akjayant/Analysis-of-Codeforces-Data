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
     
 
 
 
ll M[4][4] = {{0,1,1,0}, {1,0,0,1}, {0,1,0,0},{1,0,0,0}};
ll ans1[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
ll ans2[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
void multiply(ll a[4][4], ll b[4][4]) 
{ 
    // Creating an auxiliary matrix to store elements  
    // of the multiplication matrix 
    ll mul[4][4]; 
    for (ll i = 0; i < 4; i++) 
    { 
        for (ll j = 0; j < 4; j++) 
        { 
            mul[i][j] = 0; 
            for (ll k = 0; k < 4; k++) 
                mul[i][j] = (mul[i][j] + a[i][k]*b[k][j])%mod; 
        } 
    } 
  
    // storing the multiplication result in a[][] 
    for (ll i=0; i<4; i++) 
        for (ll j=0; j<4; j++) 
            a[i][j] = mul[i][j];  // Updating our matrix 
} 
  

  
 
//bool nprime[6005]={}; 
     
int main() 
{
 
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
ll n,m;

cin>>n>>m;
if(n<m)
swap(n,m);
ll fans1=0, fans2=0;
if(n == 1)
fans1 = 0;
else if(n==2)
fans1 = 2;
else 
{ 
  for(ll i = 0 ; i<n-2 ; i++)
  {
   multiply(ans1,M);
  }

 for(ll i = 0; i<4 ; i++)
  for(ll j = 0; j<4 ; j++)
  {
    fans1 = (fans1+ans1[i][j])%mod;
  }

  fans1 = (fans1-2+mod)%mod;

 }

 if(m == 1)
 {
    fans2 = 2;
 }
 else if(m == 2)
 {
  fans2 = 4;
 }
 else
 {
  for(ll i = 0 ; i<m-2 ; i++)
  {
   multiply(ans2,M);
  }

 for(ll i = 0; i<4 ; i++)
  for(ll j = 0; j<4 ; j++)
  {
    fans2 = (fans2+ans2[i][j])%mod;
  }

 }
 //cout<<"fans1 : "<<fans1<<" fans2: "<<fans2<<endl;
 cout<<(fans1+fans2)%mod<<endl; 

return 0;
 
}