#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_genius = 0; ngtkana_is_genius < int(n); ngtkana_is_genius++)
#define rep(i, begin, end) for(int i = int(begin); i < int(end); i++)
#define all(v) v.begin(), v.end()
#define rand(l, r) std::uniform_int_distribution<>(l, r)(mt)
using lint = long long;
auto mt = std::mt19937_64(std::random_device{}());
auto cmn = [](auto& a, auto b){if (a > b) {a = b; return true;} return false;};
auto cmx = [](auto& a, auto b){if (a < b) {a = b; return true;} return false;};
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail){
  std::cerr << " " << head;
  debug_impl(tail...);
}
#ifdef STOPIT
#define debug(...) 0
#else
#define debug(...)\
do {\
  std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
  debug_impl(__VA_ARGS__);\
  std::cerr << std::noboolalpha;\
} while (false)
#endif

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; std::swap(a, m);
    u -= t * v; std::swap(u, v);
  }
  assert(m == 1);
  return u;
}
template <typename T>
class modular {
  private:
    int value;
  public:
    constexpr modular() = default;
    constexpr modular(const modular&) = default;
    constexpr modular(modular&&) = default;
    modular& operator=(const modular&) = default;
    modular& operator=(modular&&) = default;

    template <typename U>
    modular (const U& x) {value = normalize(x);}

    template <typename U>
    static auto normalize(const U& x) {
      int v = static_cast<int>(-mod() <= x && x < mod() ? x : x % mod());
      if (v < 0) v += mod();
      return v;
    }

    auto const& operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }
    constexpr static auto mod() { return T::value; }

    auto& operator+=(const modular& other) {
      if ((value += other.value) >= mod()) value -= mod();
      return *this;
    }
    auto& operator-=(const modular& other) {
      if ((value -= other.value) < 0) value += mod();
      return *this;
    }
    template <typename U>
    auto& operator+=(const U& other) {return *this += modular(other); }
    template <typename U>
    auto& operator-=(const U& other) {return *this -= modular(other); }
    auto operator-() const { return modular(-value); }
    auto& operator++() {return *this += 1;}
    auto& operator--() {return *this -= 1;}
    auto  operator++(int) {modular result(*this); operator++(); return result;}
    auto  operator--(int) {modular result(*this); operator--(); return result;}

    template <typename U = T>
    auto& operator*=(const modular& rhs) {
      value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
      return *this;
    }
    auto& operator/=(const modular& other) {
      return *this *= modular(inverse(other.value, mod()));
    }
};
template <typename T> struct is_modular : std::false_type {};
template <typename T> struct is_modular <modular<T>> : std::true_type{};
template <typename T> constexpr bool is_modular_v = is_modular<T>::value;

template <typename T> bool operator==(const modular<T>& lhs, const modular<T>& rhs) { return lhs() == rhs(); }
template <typename T, typename U> bool operator==(const modular<T>& lhs, U rhs) { return lhs == modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const modular<T>& rhs) { return modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const modular<T>& lhs, const modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> modular<T> operator+(const modular<T>& lhs, const modular<T>& rhs) { return modular<T>(lhs) += rhs; }
template <typename T, typename U> modular<T> operator+(const modular<T>& lhs, U rhs) { return modular<T>(lhs) += rhs; }
template <typename T, typename U> modular<T> operator+(U lhs, const modular<T>& rhs) { return modular<T>(lhs) += rhs; }

template <typename T> modular<T> operator-(const modular<T>& lhs, const modular<T>& rhs) { return modular<T>(lhs) -= rhs; }
template <typename T, typename U> modular<T> operator-(const modular<T>& lhs, U rhs) { return modular<T>(lhs) -= rhs; }
template <typename T, typename U> modular<T> operator-(U lhs, const modular<T>& rhs) { return modular<T>(lhs) -= rhs; }

template <typename T> modular<T> operator*(const modular<T>& lhs, const modular<T>& rhs) { return modular<T>(lhs) *= rhs; }
template <typename T, typename U> modular<T> operator*(const modular<T>& lhs, U rhs) { return modular<T>(lhs) *= rhs; }
template <typename T, typename U> modular<T> operator*(U lhs, const modular<T>& rhs) { return modular<T>(lhs) *= rhs; }

template <typename T> modular<T> operator/(const modular<T>& lhs, const modular<T>& rhs) { return modular<T>(lhs) /= rhs; }
template <typename T, typename U> modular<T> operator/(const modular<T>& lhs, U rhs) { return modular<T>(lhs) /= rhs; }
template <typename T, typename U> modular<T> operator/(U lhs, const modular<T>& rhs) { return modular<T>(lhs) /= rhs; }

template<typename T, typename U>
modular<T> power (const modular<T>& a, U b) {
  assert(b >= 0);
  modular<T> x = a, ret = 1;
  for (; b > 0; b /= 2) {
    if (b % 2 == 1) ret *= x;
    x *= x;
  }
  return ret;
}

template <typename T>
std::string to_string(const modular<T>& a) {
  return std::to_string(a());
}
template <typename T>
auto operator<<(std::ostream& os, const T& a)
  -> std::enable_if_t<is_modular_v<T>, std::ostream&>{
    return os << a();
  }
template <typename T>
auto operator>>(std::istream& is, T& a)
  -> std::enable_if_t<is_modular_v<T>, std::istream&> {
  long long x; is >> x;
  a = T(x);
  return is;
}

// using mod_type = int;

// struct variable_mod { static mod_type value; };
// mod_type variable_mod::value;
// mod_type& mod = variable_mod::value;
// using mint = modular< variable_mod >;

constexpr int mod = 1'000'000'007;
using mint = modular<std::integral_constant<std::decay_t<decltype(mod)>, mod>>;

template < template < typename ... > class Container, typename Value >
auto runlength(Container< Value > const& v) {
  auto n = (int)v.size();
  if (n == 0)
    { return Container< std::pair< Value, int > >{}; }
  auto pos = Container< int >{};
  for (auto i = 1; i < n; i++) {
    if (v.at(i - 1) != v.at(i))
      { pos.emplace_back(i); }
  }
  pos.emplace_back(n);
  auto m = (int)pos.size();
  auto len = Container< int >(m);
  std::adjacent_difference(pos.begin(), pos.end(), len.begin());
  auto ret = Container< std::pair< Value, int > >(m);
  for (auto i = 0; i != m; i++)
    { ret.at(i) = {v.at(pos.at(i) - 1), len.at(i)}; }
  return ret;
}

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr>
std::istream& operator>> (std::istream& is, Container& v)
  { for (auto & x : v) { is >> x; } return is; }

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr >
std::ostream& operator<< (std::ostream& os, Container const& v) {
 os << "{";
  for (auto it = v.begin(); it != v.end(); it++)
    {os << (it != v.begin() ? "," : "") << *it;}
  return os << "}";
}

template < template < typename ... > class Tuple,  typename... Args, std::size_t ... Inds, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::istream& tuple_input_impl(std::istream& os, Tuple<Args...>& tuple, std::integer_sequence<std::size_t, Inds...>)
  { (void)std::initializer_list<int>{((void)(os >> std::get< Inds >(tuple)), 0)...}; return os; }
template < template < typename ... > class Tuple,  typename... Args, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::istream& operator>> (std::istream& os, Tuple<Args...>& tuple)
  { return tuple_input_impl(os, tuple, std::index_sequence_for<Args...>()); }

template < template < typename ... > class Tuple,  typename... Args, std::size_t ... Inds, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::ostream& tuple_output_impl(std::ostream& os, const Tuple<Args...>& tuple, std::integer_sequence<std::size_t, Inds...>)
  { os << "("; (void)std::initializer_list<int>{((void)(os << (Inds > 0 ? "," : "") << std::get< Inds >(tuple)), 0)...}; return os << ")"; }
template < template < typename ... > class Tuple,  typename... Args, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::ostream& operator<< (std::ostream& os, const Tuple<Args...>& tuple)
 { return tuple_output_impl(os, tuple, std::index_sequence_for<Args...>()); }

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  std::string s; std::cin >> s;
  int n = s.length();
  std::vector< char > a(n);
  std::copy(all(s), a.begin());
  auto rle = runlength(a);
  // debug(rle);

  std::vector< mint > fib(n + 1);
  fib.at(0) = 1;
  fib.at(1) = 1;
  rep(i, 2, n + 1) {
    fib.at(i) = fib.at(i - 1) + fib.at(i - 2);
  }

  mint ret = 1;
  for (auto pair : rle) {
    char c; int x; std::tie(c, x) = pair;
    if (c == 'u' || c == 'n') {
      ret *= fib.at(x);
    }
    if (c == 'w' || c == 'm') {
      ret = 0;
    }
  }
  std::cout << ret << std::endl;
  return 0;
}
