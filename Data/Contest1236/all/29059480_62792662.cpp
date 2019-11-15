#include <bits/stdc++.h>
#define rep(i,s,e) for(int i = s; i < e; i++)
#define test(t) int t; cin >> t; while(t--) 
#define iterate(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef set<int> si;
typedef long long ll;

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
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
int main() {
  ll mod = (ll) 1e9+7;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(6) << fixed;
  ll n,m;
  cin >> n >> m;
  ll val = power(2L,m,mod) - 1;
  cout << power(val,n,mod);
  return 0;
}

