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

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n = 10;
  int N = n * n;
  auto encode = [&] (int i, int j) {
    return i * n + (i % 2 == 0 ? j : n - 1 - j);
  };

  std::vector< int > a(N);
  rep(i, 0, n) rep(j, 0, n) {
    int h; std::cin >> h;
    a.at(encode(i, j)) = encode(i - h, j);
  }

  int dice = 6;
  std::vector< double > dp(N, 0);
  std::vector< double > ep(N, 0);
  rep(crr, 1, dice + 1) {
    dp.at(crr) = dice;
    ep.at(crr) = dice;
  }

  rep(i, dice + 1, N) {
    rep(j, 1, dice + 1) {
      dp.at(i) += ep.at(i - j);
    }
    dp.at(i) /= dice;
    dp.at(i)++;

    ep.at(i) = std::min(dp.at(i), dp.at(a.at(i)));
  }
  // debug(dp);
  // debug(ep);

  std::cout << std::setprecision(7) << ep.back() << std::endl;
  return 0;
}
