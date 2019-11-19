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
const int MAXN=2e5+10;;
vector<int> adj[MAXN];
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
    int n;
    cin>>n;
    vector<int> c1(n+1);
    for(int i=1;i<=n;i++)
        cin>>c1[i];

    vector<int> c2(n+1);
    for(int i=1;i<=n;i++)
        cin>>c2[i];
    vector<int> c3(n+1);
for(int i=1;i<=n;i++)
    cin>>c3[i];
    for(int i=0;i<n-1;i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    } 
    int one_count=0;
    int star=-1;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()>2)
        {
            cout<<-1;
            return 0;
        }
        if(adj[i].size()==1)
        {       one_count++;
            star=i;
        }
    }
    if(one_count!=2)
    {
        cout<<-1;
        return 0;
    }
    int mn=INF;
    vector<vector<int> > dat;
    dat.pb({1,2,3});
    dat.pb({1,3,2});
    dat.pb({2, 1,3});
    dat.pb({2, 3, 1});
    dat.pb({3, 1, 2});
    dat.pb({3, 2, 1});
    vector<int> an;
    for(auto vee:dat)
    {   
        vector<int> veee(n+1);

        queue<int> qu;
        for(auto i:vee)
            qu.push(i);
        int current=0;
        int temp_star=star;
        int par=star;
        queue<pair<int,int> > second;
        second.push({temp_star, par});
        
        while(!second.empty())
        {
        int temp_star=second.front().fi;
        int par=second.front().se;
        second.pop();

      int ve=qu.front();
            qu.pop();
            qu.push(ve);
            if(ve==1)
                current+=c1[temp_star];
            if(ve==2)
                current+=c2[temp_star];
            if(ve==3)
                current+=c3[temp_star];
        veee[temp_star]=ve;
        for(auto i:adj[temp_star])
        {
            if(i==par)
                continue;
      
            second.push({i, temp_star});

        }
        }

        if(current<mn)
        {
            mn=current;
            an=veee;
        }
    }
    cout<<mn<<endl;
    for(int i=1;i<=n;i++)
        cout<<an[i]<<" ";
//----------------------------------------------------------------------------------------------------------

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    //  cerr <<finishl<<"Time in microseconds:" <<duration.count() <<finishl<<"Time in seconds:"<<duration.count()/(1000000.0)<< finishl;
}
    