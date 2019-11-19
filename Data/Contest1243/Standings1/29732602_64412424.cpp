#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define fst first
#define snd second
#define PI (acos(-1))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define MAXN 1123456
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const int MAX_PR = 5'000'000;
bitset<MAX_PR> isprime;
vi eratosthenes_sieve(int lim) {
  isprime.set(); isprime[0] = isprime[1] = 0;
  for (int i = 4; i < lim; i += 2) isprime[i] = 0;
  for (int i = 3; i*i < lim; i += 2) if (isprime[i])
    for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
  vi pr;
  rep(i,2,lim) if (isprime[i]) pr.push_back(i);
  return pr;
}
typedef unsigned long long ull;
typedef long double ld;
ull mod_mul(ull a, ull b, ull M) {
  ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
  return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull mod_pow(ull b, ull e, ull mod) {
  ull ans = 1;
  for (; e; b = mod_mul(b, b, mod), e /= 2)
    if (e & 1) ans = mod_mul(ans, b, mod);
  return ans;
}

bool isPrime(ull n) {
  if (n < 2 || n % 6 % 4 != 1) return n - 2 < 2;
  ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, s = __builtin_ctzll(n-1), d = n >> s;
  trav(a, A) {   // ^ count trailing zeroes
    ull p = mod_pow(a, d, n), i = s;
    while (p != 1 && p != n - 1 && a % n && i--)
      p = mod_mul(p, p, n);
    if (p != n-1 && i != s) return 0;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  eratosthenes_sieve(MAX_PR);

  ll n;
  cin >> n;

  vi f;
  rep(i,2,min(n,(ll)MAX_PR)) {
    if (n%i==0 and isprime[i]) {
      f.pb(i);
      if (sz(f) >= 2) break;
      if (n/i != i and n/i > min(n, (ll)MAX_PR) and isPrime((ull)n/i)) f.pb(n/i);
    }
  }

  //trav(k,f) cerr << k << endl;

  if (sz(f) == 0) {
    cout << n << endl;
  } else if (sz(f) == 1) {
    cout << f[0] << endl;
  } else {
    cout << 1 << endl;
  }

}
