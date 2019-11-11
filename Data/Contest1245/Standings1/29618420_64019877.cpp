#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<ll, ll>
#define mp make_pair
#define pb push_back
#define vi vector<ll>
#define pd pair<double, double>
#define vp vector<pi>
#define f(i, n) for(int i = 0; i < n; i++)
#define fo(i, a, n) for(int i = a; i < n; i++)
#define mod (1000*1000*1000+7)
#define sz(x) int((x).size())
#define all(x) x.begin(),x.end()
#define DBG(v) cerr << #v << " = " << (v) << endl;
ll INF = (1ll<<61);

using namespace std;

// MODULAR INVERSE
ll modInverse(ll a, ll m){
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1){
        ll q = a / m; ll t = m;
        m = a % m, a = t;
        t = y; y = x - q * y; x = t;
    }
    if (x < 0) x += m0;
    return x;
}

ll dp[100005];
ll fib[100005];

ll fibb(ll x){
  if(x == 0 || x == 1) return fib[x] = 1;
  else if(fib[x] != -1) return fib[x];
  return fib[x] = (fibb(x-1) + fibb(x-2))%mod;
}

ll fact(ll x){
  if(x == 0) return dp[x] = 1;
  else if(dp[x] != -1) return dp[x];
  else return dp[x] = (x * ( fact(x - 1)))%mod ;
}

ll choose(ll x, ll r){
  if(x < r) return 1;
  // DBG(fact(x) * modInverse(fact(x - r), mod));
  return (1 + (modInverse(fact(r), mod) * ((fact(x) * modInverse(fact(x - r), mod))%mod) )%mod)%mod;
}

ll compute(ll x){
  return (fibb(x))%mod;
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    f(i, 100005) dp[i] = fib[i] = -1;
    string s; cin >> s;
    if(count(all(s), 'm') > 0 || count(all(s), 'w') > 0) cout << 0 << endl;
    else{
      ll ans = 1;
      int i = 0;
      while(i < sz(s)){
        // DBG(i);
        if(s[i] == 'n'){
          int j = i;
          while(j < sz(s) && s[j] == 'n') j++;
          ll k = (j - i);
          ans = (ans * compute(k)) %mod;
          i = j;
        }else if(s[i] == 'u'){
          int j = i;
          while(j < sz(s) && s[j] == 'u') j++;
          ll k = (j - i);
          ans = (ans * compute(k)) %mod;
          i = j;
        }
        else i++;
      }
      cout << ans << endl;
    }
    return 0;
}
