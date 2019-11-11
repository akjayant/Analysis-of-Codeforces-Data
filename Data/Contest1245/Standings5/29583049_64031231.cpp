#include <bits/stdc++.h>
template<int mod>
class Combination {
    std::vector<long long> fact, finv, inv;
public:
    Combination(int sz) {
        fact.resize(sz);
        finv.resize(sz);
        inv.resize(sz);
        fact[0] = 1;
        for(int i=1;i<sz;++i) {
            fact[i] = fact[i-1] * i % mod;
        }
        inv[0] = 0;
        inv[1] = 1;
        for(int i=2;i<sz;++i) {
            inv[i] = mod - inv[mod%i] * (mod/i) % mod;
        }
        finv[0] = 1;
        for(int i=1;i<sz;++i) {
            finv[i] = finv[i-1] * inv[i] % mod;
        }
    }
    long long C(long long n, long long k) {
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return (fact[n] * finv[k] % mod) * finv[n-k] % mod;
    }
    long long P(long long n, long long k) {
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fact[n] * finv[n-k] % mod;
    }
    long long H(long long n, long long k) {
        return this->C(n + k - 1, k);
    }
    long long getfact(int i) {
        return fact[i];
    }
    long long getinv(int i) {
        return inv[i];
    }
    long long getfinv(int i) {
        return finv[i];
    }
};
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  Combination<MOD> comb(100010);
  string s; cin >> s;
  int cntn = 0, cntu = 0;
  ll ansn = 1, ansu = 1;
  if(s[0] == 'm' || s[0] == 'w') {
    cout << 0 << endl;
    return 0;
  } else if(s[0] == 'u') {
    cntu = 1;
  } else if(s[0] == 'n') {
    cntn = 1;
  }
  for(int i=1;i<(int)(s.size());++i) {
    if(s[i] == 'm' || s[i] == 'w') {
      cout << 0 << endl;
      return 0;
    } else if(s[i] == 'u') {
      if(s[i-1] == 'u') {
        cntu++;
      } else if(cntn > 0) {
        ll tmp = 0;
        for(int j=1;j<=cntn/2;++j) {
          tmp += comb.C(cntn - j, j);
          tmp %= MOD;
        }
        tmp++;
        ansn *= tmp;
        ansn %= MOD;
        cntn = 0;
        cntu = 1;
      } else {
        cntu = 1;
      }
    } else if(s[i] == 'n') {
      if(s[i-1] == 'n') {
        cntn++;
      } else if(cntu > 0) {
        ll tmp = 0;
        for(int j=1;j<=cntu/2;++j) {
          tmp += comb.C(cntu - j, j);
          tmp %= MOD;
        }
        tmp++;
        ansu *= tmp;
        ansu %= MOD;
        cntu = 0;
        cntn = 1;
      } else {
        cntn = 1;
      }
    } else {
      if(cntu > 0) {
        ll tmp = 0;
        for(int j=1;j<=cntu/2;++j) {
          tmp += comb.C(cntu - j, j);
          tmp %= MOD;
        }
        tmp++;
        ansu *= tmp;
        ansu %= MOD;
        cntu = 0;
      } else if(cntn > 0) {
        ll tmp = 0;
        for(int j=1;j<=cntn/2;++j) {
          tmp += comb.C(cntn - j, j);
          tmp %= MOD;
        }
        tmp++;
        ansn *= tmp;
        ansn %= MOD;
        cntn = 0;
      }
    }
  }
  if(cntu > 0) {
    ll tmp = 0;
    for(int j=1;j<=cntu/2;++j) {
      tmp += comb.C(cntu - j, j);
      tmp %= MOD;
    }
    tmp++;
    ansu *= tmp;
    ansu %= MOD;
  } else if(cntn > 0) {
    ll tmp = 0;
    for(int j=1;j<=cntn/2;++j) {
      tmp += comb.C(cntn - j, j);
      tmp %= MOD;
    }
    tmp++;
    ansn *= tmp;
    ansn %= MOD;
  }
  cout << ansu * ansn % MOD << endl;
}
