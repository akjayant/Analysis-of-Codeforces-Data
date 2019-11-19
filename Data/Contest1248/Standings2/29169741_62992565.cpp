// Author: Tyler Wang

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt) {
  return opt ? os << *opt : os << "nullopt";
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <typename Container,
          std::enable_if_t<!std::is_convertible_v<Container, std::string_view>,
                           typename Container::const_iterator>* = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& c) {
  os << '{';
  for (auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin()) {
      os << ", ";
    }
    os << *it;
  }
  return os << '}';
}

namespace detail {

template <int I, typename... Ts>
void print_tuple(std::ostream& os, const std::tuple<Ts...>& t) {
  static_assert(0 <= I && I <= sizeof...(Ts));
  if constexpr (I != sizeof...(Ts)) {
    if constexpr (I != 0) {
      os << ", ";
    }
    os << std::get<I>(t);
    print_tuple<I + 1>(os, t);
  }
}

}  // namespace detail

template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t) {
  os << '{';
  detail::print_tuple<0>(os, t);
  return os << '}';
}

namespace detail {

template <typename T>
void print(std::string_view name, const T& val) {
  std::cerr << name << " = " << val << std::endl;
}

template <typename T1, typename... Ts>
void print(std::string_view names, const T1& val1, const Ts&... vals) {
  for (int i = 0, paren = 0; i < (int)names.size(); ++i) {
    if (names[i] == '(' || names[i] == '{') {
      ++paren;
    } else if (names[i] == ')' || names[i] == '}') {
      --paren;
    } else if (names[i] == ',' && paren == 0) {
      std::cerr << names.substr(0, i) << " = " << val1 << ',';
      return print(names.substr(i + 1), vals...);
    }
  }
}

template <typename... Ts>
void print(int line, std::string_view names, const Ts&... vals) {
  std::cerr << "  " << line << " | ";
  print(names, vals...);
}

}  // namespace detail

#ifdef TYLER
#define debug(...) detail::print(__LINE__, #__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif

template <int Mod = 1'000'000'007>
class mod_int {
  static_assert(Mod > 0);

 public:
  constexpr mod_int() : data_(0) {}

  template <typename T>
  constexpr mod_int(T val) : data_((int)(val % Mod)) {
    static_assert(std::is_integral_v<T>);
    if (data_ < 0) {
      data_ += Mod;
    }
  }

  static constexpr int modulus() { return Mod; }

  template <typename T>
  constexpr explicit operator T() const {
    return (T)data_;
  }

  constexpr mod_int& operator++() {
    if (++data_ == Mod) {
      data_ = 0;
    }
    return *this;
  }

  constexpr mod_int operator++(int) {
    mod_int t = *this;
    ++*this;
    return t;
  }

  constexpr mod_int& operator--() {
    if (data_ == 0) {
      data_ = Mod;
    }
    --data_;
    return *this;
  }

  constexpr mod_int operator--(int) {
    mod_int t = *this;
    --*this;
    return t;
  }

  constexpr mod_int operator+=(mod_int other) {
    if ((data_ += other.data_) >= Mod) {
      data_ -= Mod;
    }
    return *this;
  }

  constexpr mod_int operator-=(mod_int other) {
    if ((data_ -= other.data_) < 0) {
      data_ += Mod;
    }
    return *this;
  }

  constexpr mod_int operator*=(mod_int other) {
    data_ = (int)((long long)data_ * other.data_ % Mod);
    return *this;
  }

  constexpr mod_int operator/=(mod_int other) { return *this *= inv(other); }

  friend constexpr mod_int operator-(mod_int mi) {
    if (mi.data_ != 0) {
      mi.data_ = Mod - mi.data_;
    }
    return mi;
  }

  friend constexpr mod_int operator+(mod_int lhs, mod_int rhs) {
    return lhs += rhs;
  }

  friend constexpr mod_int operator-(mod_int lhs, mod_int rhs) {
    return lhs -= rhs;
  }

  friend constexpr mod_int operator*(mod_int lhs, mod_int rhs) {
    return lhs *= rhs;
  }

  friend constexpr mod_int operator/(mod_int lhs, mod_int rhs) {
    return lhs /= rhs;
  }

  friend constexpr bool operator==(mod_int lhs, mod_int rhs) {
    return lhs.data_ == rhs.data_;
  }

  friend constexpr bool operator!=(mod_int lhs, mod_int rhs) {
    return lhs.data_ != rhs.data_;
  }

  friend constexpr bool operator<(mod_int lhs, mod_int rhs) {
    return lhs.data_ < rhs.data_;
  }

  friend constexpr bool operator<=(mod_int lhs, mod_int rhs) {
    return lhs.data_ <= rhs.data_;
  }

  friend constexpr bool operator>(mod_int lhs, mod_int rhs) {
    return lhs.data_ > rhs.data_;
  }

  friend constexpr bool operator>=(mod_int lhs, mod_int rhs) {
    return lhs.data_ >= rhs.data_;
  }

  friend std::ostream& operator<<(std::ostream& os, mod_int mi) {
    return os << mi.data_;
  }

  friend std::istream& operator>>(std::istream& is, mod_int& mi) {
    long long val;
    is >> val;
    mi = mod_int(val);
    return is;
  }

  friend constexpr mod_int inv(mod_int mi) {
    int a = mi.data_, b = Mod;
    int x = 0, xx = 1;
    while (a != 0) {
      int q = b / a;
      int t = a;
      a = b - q * a;
      b = t;
      t = xx;
      xx = x - q * xx;
      x = t;
    }
    return mod_int(x);
  }

  template <typename T>
  friend constexpr mod_int pow(mod_int base, T expo) {
    static_assert(std::is_integral_v<T>);
    if (expo < 0) {
      base = inv(base);
      expo = -expo;
    }
    mod_int power = 1;
    for (; expo != 0; expo >>= 1) {
      if (expo & 1) {
        power *= base;
      }
      base *= base;
    }
    return power;
  }

 private:
  int data_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(12);
  std::cerr.precision(12);
  std::mt19937 rng((std::uint_fast32_t)std::chrono::high_resolution_clock::now()
                       .time_since_epoch()
                       .count());
  int n, m;
  cin >> n >> m;
  if (n < m) {
    swap(n, m);
  }
  vector<vector<mod_int<>>> dp(n, vector<mod_int<>>(2));
  dp[0][0] = 2;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] = dp[i - 1][0];
  }
  debug(dp);
  mod_int<> ans =
      (dp[n - 1][0] + dp[n - 1][1]) + (dp[m - 1][0] + dp[m - 1][1]) - 2;
  cout << ans << '\n';
  return 0;
}
