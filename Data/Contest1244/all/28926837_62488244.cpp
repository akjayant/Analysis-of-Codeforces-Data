// clang-format off
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <string_view>

#include <algorithm>
#include <numeric>
#include <limits>
#include <chrono>
#include <functional>
#include <iterator>
#include <random>
#include <complex>
#include <utility>
#include <type_traits>
#include <tuple>
#include <variant>
#include <optional>
#include <memory>

#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <valarray>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <csignal>
#include <cstdint>
#include <cstddef>

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif
#include <cassert>
#include <stdexcept>
#include <exception>

// << pair
template <typename T1, typename T2>std::ostream&operator<<(std::ostream&os,const std::pair<T1,T2>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
// << container
template<typename,template<typename...> class...>struct is_instantiation_of:public std::false_type{};
template<template<typename...>class U,template<typename...>class...Us,typename...T>struct is_instantiation_of<U<T...>,U,Us...>:public std::true_type{};
template<typename S,template<typename...>class U,template<typename...>class...Us>struct is_instantiation_of<S,U,Us...>:std::bool_constant<is_instantiation_of<S,Us...>::value>{};

template<typename C>std::ostream&_debug_go(std::ostream&,const C&);
template<typename C,typename=std::enable_if_t<is_instantiation_of<C,std::vector,std::deque,std::set,std::map,std::unordered_set,std::unordered_map,std::multiset,std::multimap,std::unordered_multiset,std::unordered_multimap,std::valarray>::value>>std::ostream&operator<<(std::ostream&os,const C&v){return _debug_go(os,v);}
template<typename T,std::size_t N> std::ostream& operator<<(std::ostream&os,const std::array<T,N>&v){return _debug_go(os,v);}
template<typename C>std::ostream& _debug_go(std::ostream&os,const C& v){bool first=true;os<<"[";for(auto i:v){if(!first)os<<", ";else first=false;os<<i;}return os<<"]";}

struct Debugger{template<typename T>Debugger&operator,(const T&v){std::cerr<<v<<" ";return *this;}} dbg;
#ifndef NDEBUG
#define debug(args...) do {dbg,args; cerr << "\n";} while(0)
#else
#define debug(args...)
#endif

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ITER(i, s, e) for (auto i((s)); i != (e); ++i)
#define IT(i, c) ITER(i, (c).begin(), (c).end())

using namespace std;

using ui = uint32_t;
using ll = int64_t;
using ull = uint64_t;
template <typename T = int> using Pt = complex<T>;

template <typename T>
T cross(const Pt<T>& a, const Pt<T>& b) { return a.real() * b.imag() - a.imag() * b.real(); }

template <typename T>
bool cmpPt(const Pt<T>& a, const Pt<T>& b) {
  return a.real() < b.real() || (a.real() == b.real() && a.imag() < b.imag());
}
// END TEMPLATE
// clang-format on

constexpr ll INF = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<array<ll, 3>> C(N);
  REP(c, 3) REP(i, N) cin >> C[i][c];
  vector<vector<int>> E(N);
  REP(i, N - 1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  vector<int> leaves;
  REP(u, N) {
    if (E[u].size() > 2) {
      cout << "-1\n";
      return 0;
    } else if (E[u].size() == 1) {
      leaves.push_back(u);
    }
  }
  if (leaves.size() != 2) {
    cout << "-1\n";
    return 0;
  }
  ll best = INF;
  vector<int> bestCs;
  REP(c0, 3) FOR(d, 1, 3) {
    int u = leaves[0], c = c0;
    vector<bool> vis(N);
    ll res = 0;
    vector<int> Cs(N, -1);
    while (!vis[u]) {
      vis[u] = true;
      Cs[u] = c;
      res += C[u][c];
      c += d;
      if (c >= 3) c -= 3;
      for (int v : E[u])
        if (!vis[v]) u = v;
    }
    if (res < best) {
      best = res;
      bestCs = Cs;
    }
  }
  cout << best << '\n';
  REP(u, N) cout << " " << bestCs[u] + 1;
  cout << '\n';

  return 0;
}
