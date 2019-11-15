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
  int max = 3;
  auto encode = [&] (char c) {
    switch(c) {
      default: throw;
      case 'R': return 0;
      case 'P': return 1;
      case 'S': return 2;
    }
  };
  auto decode = [&] (int x) {
    switch(x) {
      default: throw;
      case 0: return 'R';
      case 1: return 'P';
      case 2: return 'S';
    }
  };

  int q; std::cin >> q;
  loop(q) {
    int n; std::cin >> n;
    std::vector< int > card(max);
    std::cin >> card;

    std::vector< int > a(n);
    rep(i, 0, n) {
      char c; std::cin >> c;
      a.at(i) = encode(c);
    }

    std::vector< int > ckd(n, false);
    std::vector< int > ans(n, -1);
    int score = 0;
    rep(bob, 0, max) {
      auto alice = (bob + 1) % 3;
      rep(i, 0, n) {
        if (a.at(i) == bob && 0 < card.at(alice)) {
          ans.at(i) = alice;
          card.at(alice)--;
          score++;
        }
      }
    }
    // debug(score, ans, card);

    if (score < n - n / 2) {
      std::cout << "No" << std::endl;
      continue;
    }
    std::cout << "Yes" << std::endl;

    rep(bob, 0, max) {
      auto alice = (bob + 2) % 3;
      rep(i, 0, n) {
        if (ans.at(i) == -1 && 0 < card.at(alice)) {
          ans.at(i) = alice;
          card.at(alice)--;
        }
      }
    }
    // debug(ans, card);
    assert(std::all_of(all(card), [](auto x){ return x == 0; }));
    assert(std::all_of(all(ans), [](auto x){ return 0 <= x; }));

    rep(i, 0, n) {
      std::cout << decode(ans.at(i));
    }
    std::cout << std::endl;
  }
  return 0;
}
