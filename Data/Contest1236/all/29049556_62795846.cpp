// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░

//PointBlank's code (⌐■_■)
 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define repp(i, a, b) for(ll i = a; i <= b; i++)
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define rrep(i, b, a) for(ll i = b; i >= a; i--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define mem(a, b) memset(a, b, sizeof(a));
#define mem0(a) memset(a, 0, sizeof(a));
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define in_edges(m) repp(i, 1, m){ll a, b; cin >> a >> b; v[a].pb(b), v[b].pb(a);}
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define endl "\n"

const ll MOD = 1000000007;
const ll NICE = 69;

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

int main() //PointBlank's code ¯\_(ツ)_/¯
{
    quickio
    ll n, m;
    cin >> n >> m;
    ll pp = power(2, m, MOD);
    ll res = (pp - 1 + MOD) % MOD;
    pp = power(res, n, MOD);
    cout << pp;
}