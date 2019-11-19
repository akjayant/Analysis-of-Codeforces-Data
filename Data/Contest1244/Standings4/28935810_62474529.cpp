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
  ll res = 1;
  for (; n > 0; n >>= 1) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
  }
  return res;
}

const int MAX = 1000005; 
vl a;
vl g[MAX];
void dfs(ll u,ll p)
{
  a.pb(u);
  for(auto x:g[u])
  {
    if(x!=p)
    {
      dfs(x,u);
    }
  }
}
int main()
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
    ll c[3][n+1];
    for(ll i=0;i<3;i++)
    {
      for(ll j=1;j<=n;j++)
      cin>>c[i][j];
    }
    for(ll i=1;i<n;i++)
    {
      ll u,v;
      cin>>u>>v;
      g[u].pb(v);
      g[v].pb(u);
      if(g[u].size()>2||g[v].size()>2)
      {
        cout<<-1;
        return 0;
      }
    }

    for(ll i=1;i<=n;i++)
    {
      if(g[i].size()==1)
      {
        dfs(i,0);
        break;
      }
    }
    vl v1,v2,v3;
    for(ll i=0;i<n;i++)
    {
      if(i%3==0)
      v1.pb(a[i]);
      else if(i%3==1)
      v2.pb(a[i]);
      else
      {
        v3.pb(a[i]);
      }
      
    }
    ll mini=1e18;
    ll ans1=0,ans2=0;
    for(ll i=0;i<3;i++)
    {
      for(ll j=0;j<3;j++)
      {
        if(j==i)
          continue;
          ll ans=0;
          for(ll k=0;k<3;k++)
          {
            if(k!=i&&k!=j)
            {
              for(ll h=0;h<v1.size();h++)
              {
                ans+=c[i][v1[h]];
              }
              for(ll h=0;h<v2.size();h++)
              {
                ans+=c[j][v2[h]];
              }
              for(ll h=0;h<v3.size();h++)
              {
                ans+=c[k][v3[h]];
              }
            }
          }
          if(ans<mini)
          {
            mini=ans;
            ans1=i;
            ans2=j;

          }
        
      }
    }
  ll col[n+1];
    cout<<mini<<endl;
    for(ll i=0;i<v1.size();i++)
    {
      col[v1[i]]=ans1+1;
    }
    for(ll i=0;i<v2.size();i++)
    {
      col[v2[i]]=ans2+1;
    }
    for(ll i=0;i<v3.size();i++)
    {
      col[v3[i]]=6-(ans2+1)-(ans1+1);
    }
    for(ll i=1;i<=n;i++)
    {
      cout<<col[i]<<" ";
    }
    
      
  
        
    
    
  
  
  
}
