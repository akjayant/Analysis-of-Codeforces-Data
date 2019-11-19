#include <bits/stdc++.h>
using namespace std;
  
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 
  
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
#define debug cout << "Hold right there sparky.....\n";
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) {os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
  
typedef long long int ll;
  
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod =1e9+7;
const ll maxn =5*100001;
    ll power(ll x, ll n) {
      x%=mod;
      ll res = 1;
      for (; n > 0; n >>= 1) {
        if (n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
      }
      return res;
    }

int32_t main()
{
   #ifndef ONLINE_JUDGE
      // for getting input from input.txt
      freopen("input.txt", "r", stdin);
      // for writing output to output.txt
      freopen("output.txt", "w", stdout);
      #endif
    
    IOS
    ll n;
    cin>>n;
    vl v;
    if(n==1)
    {
      cout<<1<<endl;
      return 0;
    }
    for(ll i=1;i*i<=n;i++)
    {
      if(n%i==0)
      {
        v.pb(i);
        if(i*i!=n)
          v.pb(n/i);
      }
    }
    ll g=0;
    for(ll i=0;i<v.size();i++)
    {
      if(v[i]!=1)
      {
        g=__gcd(g,v[i]);
      }
    }
    cout<<g<<endl;
  
    
}
  
           
         
       
