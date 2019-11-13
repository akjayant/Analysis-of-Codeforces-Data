#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

template<long long mod>
class modint{
private:
  long long a;
public:
  constexpr modint(const long long x = 0) noexcept : a(x%mod) {}
  constexpr long long& value() noexcept { return a; }
  constexpr const long long& value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint& operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if(a >= mod) a -= mod;
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if(a < rhs.a) a += mod;
    a -= rhs.a;
    return *this;
  }
  constexpr modint& operator*=(const modint rhs) noexcept {
    a = a*rhs.a%mod;
    return *this;
  }
  constexpr modint& operator/=(modint rhs) noexcept {
    long long k = mod-2;
    while(k > 0){
      if(k&1){
        *this *= rhs;
      }
      rhs *= rhs;
      k /= 2;
    }
    return *this;
  }
  friend ostream& operator<<(ostream &os, const modint &X){
    return os << X.a;
  }
  friend istream& operator>>(istream &is, modint &X){
    is >> X.a;
    X.a %= mod;
    if(X.a < 0) X.a += mod;
    return is;
  }
};

int main(){
  using mint = modint<(int)1e9+7>;
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  size_t n = s.length();
  vector<mint> dp(n+1,0);
  dp[0] = 1;
  for(size_t i = 0; i < n; ++i){
    if(s[i] == 'm' or s[i] == 'w'){
      cout << 0 << endl;
      return 0;
    }
    if(i > 0 and s[i] == s[i-1] and (s[i] == 'n' or s[i] == 'u')){
      dp[i+1] += dp[i-1];
    }
    dp[i+1] += dp[i];
  }
  cout << dp.back() << endl;
}
