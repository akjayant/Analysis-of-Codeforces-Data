#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repr(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define repChar(i) for (char i = 'a'; i <= 'z'; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;


const ll mod = 1000000007;

// a^b % m
ll modPow(ll a, ll b) {
  if (b == 0) return 1;
  else if (b == 1) return a % mod;
  else if (b % 2 == 0) return modPow((a*a)%mod, b/2);
  else return a * modPow((a*a)%mod, (b-1)/2) % mod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m; cin >> n >> m;

  cout << modPow(modPow(2,m)-1,n) << endl;
}
