    /*
       THE DARK NIGHT RISES
    I LOVE YOU 72 AND WILL FOREVER DO SO
    Patience, Persistence, Perseverance, Passion, Purpose
    */
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    typedef unsigned long long int ull;
    typedef long double ld;
    const int N = 2e5 + 20 ;
    #define F first
    #define S second
    # define all(v) v.begin(),v.end()
    #define rall(v) v.rbegin(),v.rend()
    #define pb push_back
    #define mk make_pair
    #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define rep(i,a,b) for(ll i=a;i<b;i++)
    typedef pair<int, int> ii;
    typedef vector<int> vi;
    typedef vector<ii> vii;
    typedef vector<vi> vvi;
    typedef vector<vii> vvii;
    #define sz(x)       (int)x.size()
    const long long int mod=1e9 + 7;
    const long double EPS=1e-12;
    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x );
    #define bitcount( x ) __builtin_popcountll( x )
     
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
     
    ll fib[N] ;
     
    ll power(ll x, ll y){
        x %= mod;
        ll ans = 1;
        while(y){
            if(y & 1)
                ans = (ans * x) % mod;
            y >>= 1LL;
            x = (x * x) % mod;
        }
        return ans;
    }
    ll mul(ll a, ll b){ return ((a % mod) * (b % mod)) % mod; }
    ll add(ll a, ll b) {     return ((a % mod) + (b % mod)) % mod; }
    ll sub(ll a, ll b) { return ((a%mod) - (b % mod)+ mod) % mod ; }
    ll divi(ll a, ll b){
        return(mul(a, power(b, mod - 2)) % mod);
    }
     
    int solve()
    {
      ll n , m;
      cin >> n >> m ;
      fib[0] = 0 ;
      fib[1] = 2 ,fib[2] = 4 ;
      rep(i,3,100006){fib[i] = add(fib[i-1],fib[i-2]);}
      ll x = sub(fib[n],2);
      cout <<add(fib[m],x);
     
    }
    int main()
    {
      fast;
      ll t;
      t=1;
      //cin>>t;
      while(t--)
      {
        solve();
      }
     
      return 0;
    }
    // Patience, Persistence, Perseverance, Passion, Purpose
    // I LOVE YOU 72 AND WILL FOREVER DO SO.