#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

ll fastexp (ll a, ll b, ll n) {
  ll res = 1;
  while (b) {
      if (b & 1) res = res*a%n; 
      a = a*a%n;
      b >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
  const ll mod = 1e9+7;
  ll n, m;
  cin >> n >> m;
  ll b = (fastexp(2, m, mod)-1+mod)%mod;
  cout << fastexp(b, n,mod)<<endl;
}

