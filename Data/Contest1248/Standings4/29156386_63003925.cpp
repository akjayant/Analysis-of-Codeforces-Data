/*
....................
....................
*/
#include<bits/stdc++.h>
#define ll long long int
#define here cout<<"here\n"
#define pb push_back
#define mp make_pair
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf printf
#define pfi(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
using namespace std;

const ll m = 1e9+7;

const int MAX = 100005;

ll gcdExtended(ll a, ll b, ll *x, ll *y); 
  
// Function to find modulo inverse of b. It returns 
// -1 when inverse doesn't 
ll modInverse(ll b, ll m) 
{ 
    ll x, y; // used in extended GCD algorithm 
    ll g = gcdExtended(b, m, &x, &y); 
  
    // Return -1 if b and m are not co-prime 
   
  
    // m is added to handle negative x 
    return (x%m + m) % m; 
} 
  
// Function to compute a/b under modlo m 
ll modDivide(ll a, ll b, ll m) 
{ 
    a = a % m; 
    ll inv = modInverse(b, m); 
    return ((inv * a) % m); 
} 
  
// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

ll modFact(ll n, ll p) 
{ 
    if (n >= p) 
        return 0; 
  
    ll result = 1; 
    for (ll i = 1; i <= n; i++) 
        result = (result * i) % p; 
  
    return result; 
} 

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll A[100005]={0};
    ll i,j,k=0;
    A[0]=1;
    for(i=1;i<100005;i++)
    {
        A[i]=A[i-1]*i;
        A[i]%=m;
    }
    ll sum=0;
    ll lo=0;
    ll n,mo;
    cin>>n>>mo;
    for(i=0;i<=n/2;i++)
    {
        k=n-i;
        j=i;
        lo=A[k];
        lo=modDivide(lo,A[j],m);
        lo=modDivide(lo,A[k-j],m);
       // cout<<lo<<endl;
        sum+=2*lo;
        sum%=m;


    }
   // cout<<sum<<endl;
    for(i=1;i<=mo/2;i++)
    {
        k=mo-i;
        j=i;
        lo=A[k];
        lo=modDivide(lo,A[j],m);
        lo=modDivide(lo,A[k-j],m);
      //  cout<<lo<<endl;
        sum+=2*lo;
        sum%=m;

    }

    cout<<sum%m<<endl;
    
    return 0;
}