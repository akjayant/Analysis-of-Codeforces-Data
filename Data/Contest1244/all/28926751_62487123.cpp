//--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR
    
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define REDL(a ,n) vll a(n);for(ll i=0;i<n;i++) cin>>a[i];
#define REPR(i, n) for(int i=0;i<n;i++ )
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(X)  X.begin() ,  X.end()
#define reset(X) memset(X, 0, sizeof(X))
#define endl '\n'
#define  int long long

//------------------------------_WARNINGG---------------









//-----------------------------TEMPLATES------------------TEMPLATES---------------------------TEMPLATES---------------------------------
//-----------------------------TEMPLATES------------------TEMPLATES---------------------------TEMPLATES---------------------------------
    
//--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF----------------------------TYPEDEF
//--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF----------------------------TYPEDEF
    
typedef  long long ll;
typedef double ld;
typedef pair<ll,ll> pll;
typedef pair<ll,ll> pii;
typedef vector<ll> vll;
typedef vector<int> vi;    
    
//--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS
//--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS
    
const int INF=1e18+10;
const ll mod=1000000007;
const ld PI=acos(-1);    
    
    
    
    
    
//------------------IGNOREABLE_CONTENT------------------IGNOREABLE_CONTENT------------------IGNOREABLE_CONTENT------------------IGNOREABLE_CONTENT
    
    
    
// To find GCD of a and b
ll gcd(ll a, ll b);
    
    
// To compute x raised to power y under modulo m
    // To compute x^y under modulo m
int power(int x,  int y, int p) 
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
// Function to find modular inverse of a under modulo m
// Assumption: m is prime
ll modInverse(ll a, ll m=mod)
{
    ll g =1;
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        return power(a, m-2, m);
    }
}
    
    
// Function to return gcd of a and b
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
void coordinate_compress(vector<int>& a)
{
    set<int> b;
    for(auto i:a)
        b.insert(i);
    map<int,int> da;
    int counter=0;
    for(auto i:b)
        da[i]=counter++;
    for(auto &i:a)
        i=da[i]; 
}

//----------------------MAIN______________________________MAIN__________________MAINco
int f(const vector<int> &a, const int mid, const int s)
{
    int star=s;
    int end=mid+s;
    int cost=0;
    for(auto i:a)
    {
        if(i<star)
            cost+=star-i;
        if(i>end)
            cost+=i-end;
    }
    return cost;
}
bool func(const vector<int> & a, const int mid, const int k)
{
int B=1e9+10;
int A=0;
    while(B - A > 4)
{
    int m1 = (A + B) / 2;
    int m2 = (A + B) / 2 + 1;

    if(f(a,mid,m1) > f(a, mid,m2))
       A = m1;
    else
       B = m2;
}

int ans = INF;

for(int i = A; i <= B; i++)
    ans = min(ans , f(a, mid, i));
if(ans<=k)
    return true;
return false;
}
signed main()
{
    
    
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cout.tie(0);
        
    #ifndef ONLINE_JUDGE
        freopen ("INPUT.txt" , "r" , stdin);
        // freopen ("OUTPUT.txt" , "w" , stdout);
    #endif
//-----------------------------------------------------------------------------------------------------------
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i:a)
        cin>>i;
    int lo=0, hi=1e9+10;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        bool ch=func(a, mid , k);
        if(ch)
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
        
    }
    cout<<lo<<endl;
//----------------------------------------------------------------------------------------------------------

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    //  cerr <<finishl<<"Time in microseconds:" <<duration.count() <<finishl<<"Time in seconds:"<<duration.count()/(1000000.0)<< finishl;
}
    