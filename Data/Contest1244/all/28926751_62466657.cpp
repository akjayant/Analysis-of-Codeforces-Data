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
    
const ll INF=1e18+10;
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
//------------------WORK--------------------
const int MAXN=1e6+100;
int t[4*MAXN];
/*
void build(vector<int> & a , int v, int tl, int tr)
{
    if(tl==tr)
    {
        t[v].gcd=a[tl];
        t[v].sma=a[tl];
        t[v].smaf=1;
        return;
    }
    int tm=(tl+tr)/2;
    build(a, 2*v, tl, tm);
    build(a, 2*v+1, tm+1, tr);
    t[v]=combine(t[2*v],t[2*v+1]);
}*/
int query(int v, int tl, int tr, int pos)
{
    if(tl==tr)
    {
        return t[v];
        
    }
   int tm=(tl+tr)/2;
    if(t[v]!=0)
    {
        t[2*v]=t[v];
        t[2*v+1]=t[v]+(tm-tl+1);
        t[v]=0;
    }
    if(tm>=pos)
       return query(2*v, tl, tm,  pos);
    else
       return query(2*v+1, tm+1, tr, pos);
    

}
void update(int v, int tl, int tr,int l, int r, int k)
{

    if(l>r)
        return ;
    if(l==tl && r==tr)
    {
        t[v]=k;
        return;
    } 
    int tm=(tl+tr)/2;
   if(t[v]!=0)
    {
        t[2*v]=t[v];
        t[2*v+1]=t[v]+(tm-tl+1);
        t[v]=0;
    }
    update(2*v, tl, tm, l, min(tm , r), k);
    
    update(2*v+1, tm+1, tr, max(l, tm+1), r, k+((l<=tm && tm<=r)?(tm-l+1):0)); 
        

}
//----------------------MAIN______________________________MAIN__________________MAIN
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
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        int k;
        cin>>k;
        int mn=INF;
        int xo, yo;
        for(int x=0;x<=k;x++)
        {
            for(int y=0;y<=k;y++)
            {
                if(x+y<=k)
                {
                    if(c*x>=a)
                    {
                        if(d*y>=b)
                        {
                            if(x+y<mn)
                            {
                                mn=x+y;
                                xo=x;
                                yo=y;
                            }
         
                        }
                    }
                }
            }
        }
        if(mn==INF)
            mn=-1;

        
        if(mn!=-1)
        {
            cout<<xo<<" "<<yo<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        
    }
//----------------------------------------------------------------------------------------------------------

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    //  cerr <<finishl<<"Time in microseconds:" <<duration.count() <<finishl<<"Time in seconds:"<<duration.count()/(1000000.0)<< finishl;
}
    