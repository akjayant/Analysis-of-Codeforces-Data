#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int P = 1e9 + 7, N = 1e5;
ll fact[N + 1], facti[N + 1];



ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1;  
    return gcd; 
}

ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    ll res = (x%m + m) % m; 
    return res;
} 

ll nCr(ll n, ll r) {
  ll ans = (fact[n] * facti[r]) % P;
  ans = (ans * facti[n - r]) % P;
  return ans;
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long x = 1;
  fact[0] = 1;
  facti[0] = modInverse(1, P);
  for (int i = 1; i <= N; i++) {
    fact[i] = (i * fact[i - 1]) % P;
    facti[i] = modInverse(fact[i], P);
  }
  int n, m;
  ll ans = 0;
  cin >> n >> m;
  for (int i = 1; i <= n / 2; i++) {
    ans = (ans + nCr(n - i, i)) % P;
  }
  for (int i = 1; i <= m / 2; i++) {
    ans = (ans + nCr(m - i, i)) % P;
  }
  ans = ((ans + 1) * 2) % P;
  cout << ans;
  return 0;
} 